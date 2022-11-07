#include <iostream>
#include <vector>
using namespace std;

#define MAP_SIZE 9

bool row_used[MAP_SIZE][MAP_SIZE];
bool col_used[MAP_SIZE][MAP_SIZE];
bool area_used[MAP_SIZE/3][MAP_SIZE/3][MAP_SIZE];

bool MakeCorrectMap(vector<vector<int>>& map, int startX, int startY)
{
    bool isFind = false;
    int i,j;
    for(j=startY;j<MAP_SIZE;j++)
    {
        i = startX;
        if(j != startY)
        {
            i=0;
        }
        for(;i<MAP_SIZE;i++)
        {
            if(map[j][i] == 0)
            {
                isFind = true;
                for(int k=0;k<MAP_SIZE;k++)
                {
                    if( row_used[j][k] == false &&
                        col_used[i][k] == false &&
                        area_used[j/3][i/3][k] == false )
                    {
                        map[j][i] = k+1;
                        row_used[j][k] = true;
                        col_used[i][k] = true;
                        area_used[j/3][i/3][k] = true;
                        if( true == MakeCorrectMap(map, i+1, j) )
                        {
                            return true;
                        }
                        row_used[j][k] = false;
                        col_used[i][k] = false;
                        area_used[j/3][i/3][k] = false;
                        map[j][i] = 0;
                    }
                }
            }
            if(isFind == true)
            {
                break;
            }
        }
        if(isFind == true)
        {
            break;
        }
    }
    if( i == MAP_SIZE &&
        j == MAP_SIZE )
    {
        return true;    
    }
    return false;
}

int main()
{
    vector<vector<int>> map(MAP_SIZE);
    for(int j=0;j<MAP_SIZE;j++)
    {
        string str;
        cin >> str;
        map[j].resize(MAP_SIZE);
        for(int i=0;i<MAP_SIZE;i++)
        {
            map[j][i] = int(str[i]-'0');
            if( map[j][i] != 0)
            {
                row_used[j][map[j][i]-1]=true;
                col_used[i][map[j][i]-1]=true;
                area_used[j/3][i/3][map[j][i]-1]=true;
            }
        }
    }

    MakeCorrectMap(map, 0, 0);
    
    for(int j=0;j<MAP_SIZE;j++)
    {
        for(int i=0;i<MAP_SIZE;i++)
        {
            cout << map[j][i];
        }
        cout << endl;
    }
}