#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <memory.h>

using namespace std;

#define INVALID_DIST 0x7fffffff

int N, M;
int areaCnt;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(vector<vector<int>>& map, int y, int x, int val)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    map[y][x] = val;

    while(!q.empty())
    {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if(nextY < N && nextY >= 0 && nextX < M && nextX >= 0)
            {
                if( map[nextY][nextX] != val && 
                    map[nextY][nextX] == 1 )
                {
                    q.push({nextY,nextX});
                    map[nextY][nextX] = val;
                }
            }
        }
    }
}

vector<int> MakeArea(vector<vector<int>>& map)
{
    vector<int> areaList;
    int areaNum = 2;
    for(int y=0;y<map.size();y++)
    {
        for(int x=0;x<map[y].size();x++)
        {
            if( map[y][x] == 1)
            {
                areaList.push_back(areaNum);
                bfs(map, y, x, areaNum++);
            }
        }
    }
    return areaList;
}

int GetMinimumDist(vector<vector<int>>& map, int areaNum1, int areaNum2)
{
    int minDist = INVALID_DIST;
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<M;x++)
        {
            for(int y2=0;y2<N;y2++)
            {
                for(int x2=0;x2<M;x2++)
                {
                    if(map[y][x] == areaNum1 && map[y2][x2]==areaNum2)
                    {
                        int dist = INVALID_DIST;
                        if( y == y2 )
                        {
                            int minX = min(x,x2);
                            int maxX = max(x,x2);
                            bool isValid = true;
                            for(int i=minX+1;i<maxX;i++)
                            {
                                if( map[y][i] != 0)
                                {
                                    isValid = false;
                                    break;
                                }
                            }
                            if( isValid )
                            {
                                dist = abs(x-x2)-1;
                            }
                        }
                        else if(x==x2)
                        {
                            int minY = min(y,y2);
                            int maxY = max(y,y2);
                            bool isValid = true;
                            for(int i=minY+1;i<maxY;i++)
                            {
                                if( map[i][x] != 0)
                                {
                                    isValid = false;
                                    break;
                                }
                            }
                            if( isValid )
                            {
                                dist = abs(y-y2)-1;
                            }
                        }

                        if( dist >= 2) minDist = min(dist, minDist);
                    }
                }
            }
        }
    }
    return minDist;
}

int MakeEdges(vector<vector<int>>& map, vector<tuple<int,int,int>>& edges)
{
    vector<int> areaList = MakeArea(map);
    for(int i=0;i<areaList.size();i++)
    {
        for(int j=i+1;j<areaList.size();j++)
        {
            int dist = GetMinimumDist(map, areaList[i], areaList[j]);
            if( dist != INVALID_DIST)
            {
                edges.push_back({dist, areaList[j], areaList[i]});
            }
        }
    }
    sort(edges.begin(),edges.end());
    return areaList.size();
}

int GetParent(vector<int>& parentIdxs, int node)
{
    if( parentIdxs[node] == 0) return node;
    else return parentIdxs[node] = GetParent(parentIdxs, parentIdxs[node]);
}

bool IsSameParent(vector<int>& parentIdxs, int node1, int node2)
{
    int parent1 = GetParent(parentIdxs,node1);
    int parent2 = GetParent(parentIdxs,node2);

    if( parent1 == parent2 && parent1 != 0) return true;
    else return false;
}

void UnionSet(vector<int>& parentIdxs, int node1, int node2)
{
    int parent1 = GetParent(parentIdxs,node1);
    int parent2 = GetParent(parentIdxs,node2);

    parentIdxs[parent1] = parent2;
}

int GetMinimumCosts(int areaCnt, vector<tuple<int,int,int>>& edges)
{
    vector<int> parentIdxs(36, 0);
    int bridgeCnt=0;
    int cost=0;
    for(tuple<int,int,int>& edge : edges)
    {
        if(!IsSameParent(parentIdxs, get<1>(edge), get<2>(edge)))
        {
            UnionSet(parentIdxs, get<1>(edge), get<2>(edge));
            cost += get<0>(edge);
            bridgeCnt+=1;
        }
    }

    if( bridgeCnt != areaCnt-1)
    {
        return -1;
    }
    else
    {
        return cost;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> map(N);
    for(int i=0;i<N;i++)
    {
        map[i].resize(M,0);
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
        }
    }

    vector<tuple<int,int,int>> edges;
    int areaCnt = MakeEdges(map, edges);
    cout << GetMinimumCosts(areaCnt, edges);
}