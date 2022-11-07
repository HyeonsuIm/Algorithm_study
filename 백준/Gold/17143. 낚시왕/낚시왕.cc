#include <iostream>
#include <vector>

using namespace std;

struct SharkInfo
{
    int s;
    int d;
    int z;
};

int dx[5] = {0, 0,0,1,-1};
int dy[5] = {0, -1,1,0,0};

int FinishingShark(vector<vector<SharkInfo*>>& map, int col)
{
    int rows = map.size();
    int i;
    for(i=0;i<rows;i++)
    {
        if(map[i][col] != NULL)
        {
            break;
        }
    }

    int score = 0;;
    if( i != rows )
    {
        score = map[i][col]->z;
        map[i][col] = NULL;
    }
    return score;
}

void MoveShark(const vector<vector<SharkInfo*>>& map, vector<vector<SharkInfo*>>& mapResult, int j, int i, SharkInfo& shark)
{
    int tempI = i;
    int tempJ = j;
    int rows = map.size();
    int cols = map[0].size();
    int moveCnt = shark.s;
    int remainX = dx[shark.d] *  moveCnt;
    while(remainX!=0)
    {
        if(remainX > 0)
        {
            if( i + remainX >= cols )
            {
                remainX -= cols-1-i;
                i = cols-1;
            }
            else
            {
                i += remainX;
                remainX = 0;
                shark.d = 3;
            }
        } 
        else
        {
            if( i + remainX < 0 )
            {
                remainX += i;
                i = 0;

            }
            else
            {
                i += remainX;
                remainX = 0;
                shark.d = 4;
            }
        }
        remainX = -remainX;
    }

    int remainY = dy[shark.d] * moveCnt;
    while(remainY!=0)
    {
        if(remainY > 0)
        {
            if( j + remainY >= rows )
            {
                remainY -= rows-1-j;
                j = rows-1;
            }
            else
            {
                j += remainY;
                remainY = 0;
                shark.d = 2;
            }
        } 
        else
        {
            if( j + remainY < 0 )
            {
                remainY += j;
                j = 0;
            }
            else
            {
                j += remainY;
                remainY = 0;
                shark.d = 1;
            }
        }
        remainY = -remainY;
    }

    bool isInsert=true;
    if(mapResult[j][i] != NULL)
    {
        if( mapResult[j][i]->z >= shark.z )
        {
            isInsert=false;
        }
    }

    if(isInsert)
    {
        mapResult[j][i] = &shark;
    }
}

void MoveShark(vector<vector<SharkInfo*>>& map)
{
    vector<vector<SharkInfo*>> mapResult(map.size());
    for(int i=0;i<map.size();i++)
    {
        mapResult[i].assign(map[i].size(), NULL);
    }
    int rows = map.size();
    for(int j=0;j<rows;j++)
    {
        int cols = map[j].size();
        for(int i=0;i<cols;i++)
        {
            if(map[j][i] != NULL)
            {
                MoveShark(map,mapResult, j,i,*map[j][i]);
            }
        }
    }
    map = mapResult;
}

int main()
{
    int rows,cols,sharkCnt;
    cin >> rows >> cols >> sharkCnt;
    vector<SharkInfo> sharkInfos(sharkCnt);
    vector<vector<SharkInfo*>> map(rows);
    for(int i=0;i<rows;i++)
    {
        map[i].assign(cols,NULL);
    }

    for(int i=0;i<sharkCnt;i++)
    {
        int r,c;
        SharkInfo& s = sharkInfos[i];
        cin >> r >> c >> s.s >> s.d >> s.z;
        r-=1;
        c-=1;
        map[r][c] = &sharkInfos[i];
    }

    int result = 0;
    for(int i=0;i<cols;i++)
    {
        result += FinishingShark(map, i);
        MoveShark(map);
    }
    cout << result;
}