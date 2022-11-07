#include <iostream>
#include <vector>

using namespace std;

void DrawStar(vector<vector<char>>& map, int startX, int startY, int size)
{
    if(size > 3)
    {
        int nextSize = size/3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i!=1 || j!=1)
                {
                    DrawStar(map, startX+nextSize*i, startY+nextSize*j,nextSize);
                }
            }
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i!=1 || j!=1)
                {
                    map[startX+i][startY+j]='*';
                }
            }
        }
    }
}

int main()
{
    int size;
    cin >> size;

    vector<vector<char>> map(size);
    for(int i=0;i<size;i++)
    {
        map[i].assign(size,' ');
    }
    DrawStar(map, 0, 0, size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}