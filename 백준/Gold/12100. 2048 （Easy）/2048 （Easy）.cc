#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MOVE_LIST 4
int dx[MOVE_LIST]={1,-1,0,0};
int dy[MOVE_LIST]={0,0,1,-1};

void initMap(int N, vector<vector<int>>& map)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            map[i][j] = 0;
        }
    }
}

void copyMap(int N, const vector<vector<int>>& map, vector<vector<int>>& copyMap)
{
    copyMap.clear();
    copyMap.resize(N);
    for(int i=0;i<N;i++)
    {
        copyMap[i].resize(N);
        for(int j=0;j<N;j++)
        {
            copyMap[i][j] = map[i][j];
        }
    }
}


int moveMap(const vector<vector<int>>& map, int k, vector<vector<int>>& result)
{
    int startX = 0;
    int endX = map.size();
    int startY = 0;
    int endY = map.size();
    if(dx[k] != 0)
    {
        if (dx[k] > 0)
        {
            startX=map.size()-1;
            endX = -1;
        }
        for(int j=startY;j!=endY;j++)
        {
            int prevVal = -1;
            int storeI = startX;
            for(int i=startX;i!=endX;i-=dx[k])
            {
                if(map[j][i] != 0)
                {
                    if( prevVal == -1)
                    {
                        prevVal = map[j][i];
                        result[j][storeI] = prevVal;
                    }
                    else if(prevVal != map[j][i])
                    {
                        storeI-=dx[k];
                        prevVal = map[j][i];
                        result[j][storeI] = prevVal;
                    }
                    else
                    {
                        result[j][storeI]*=2;
                        prevVal = -1;
                        storeI-=dx[k];
                    }
                }
            }
        }
    }
    else
    {
        if(dy[k] > 0)
        {
            startY=map.size()-1;
            endY = -1;
        }
        for(int i=startX;i!=endX;i++)
        {
            int prevVal = -1;
            int storeJ = startY;
            for(int j=startY;j!=endY;j-=dy[k])
            {
                if(map[j][i] != 0)
                {
                    if( prevVal == -1)
                    {
                        prevVal = map[j][i];
                        result[storeJ][i] = prevVal;
                    }
                    else if(prevVal != map[j][i])
                    {
                        storeJ-=dy[k];
                        prevVal = map[j][i];
                        result[storeJ][i] = prevVal;
                    }
                    else
                    {
                        result[storeJ][i]*=2;
                        prevVal = -1;
                        storeJ-=dy[k];
                    }
                }
            }
        }
    }

    for(int i=0;i<map.size();i++)
    {
        for(int j=0;j<map.size();j++)
        {
            if(map[i][j] != result[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> map(N);
    vector<vector<int>> map_temp(N);
    int bestBlockVal = 0;
    for(int i=0;i<N;i++)
    {
        map[i].resize(N);
        map_temp[i].resize(N);
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
        }
    }

    if(N==1)
    {
        cout << map[0][0];
        return 0;
    }
    queue<pair<int, vector<vector<int>>>> q;
    q.push(make_pair(0, map));
    while(true)
    {
        int cost = q.front().first;
        copyMap(N, q.front().second, map);
        q.pop();
        if(cost == 5)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    bestBlockVal = max(bestBlockVal, map[i][j]);
                }
            }
        }
        else if(cost > 6)
        {
            break;
        }
        for(int i=0;i<MOVE_LIST;i++)
        {
            initMap(N,map_temp);
            if(moveMap(map, i, map_temp))
            {
                q.push(make_pair(cost+1, map_temp));
            }
        }
    }

    cout << bestBlockVal;
    return 0;
}