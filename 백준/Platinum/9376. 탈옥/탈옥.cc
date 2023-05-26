#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INVALID_COST 0x7fffffff

int w, h;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

struct Expand
{
    int cost;
    int y;
    int x;
    bool operator<(const Expand& rhs) const
    {
        return cost > rhs.cost;
    }
};

vector<pair<int,int>> GetStartPosition(vector<vector<char>>& map)
{
    vector<pair<int,int>> positions;
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            if(map[y][x] == '$') positions.push_back({y,x});
        }
    }
    return positions;
}

vector<vector<int>> MakeMoveMap(vector<vector<char>>& map, int y, int x)
{
    vector<vector<int>> visitedCost(h);
    for(int y=0;y<h;y++)
    {
        visitedCost[y].assign(w,INVALID_COST);
    }
    priority_queue<Expand> pq;
    pq.push({0,y,x});
    visitedCost[y][x]=0;
    while(!pq.empty())
    {
        int cost = pq.top().cost;
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();

        for(int d=0;d<4;d++)
        {
            int nextY = y+dy[d];
            int nextX = x+dx[d];
            if(nextY < h && nextY >= 0 && nextX < w && nextX >= 0)
            {
                int nextCost = cost;
                if( map[nextY][nextX] == '#' )
                {
                    nextCost +=1;
                }

                if(map[nextY][nextX] != '*')
                {
                    if(visitedCost[nextY][nextX] > nextCost)
                    {
                        pq.push({nextCost, nextY, nextX});
                        visitedCost[nextY][nextX] = nextCost;
                    }
                }
            }
        }
    }
    return visitedCost;
}

int GetMinOpenDoor(vector<vector<char>>& map)
{
    vector<pair<int,int>> startPositions = GetStartPosition(map);
    vector<vector<int>> map1 = MakeMoveMap(map, 0,0);
    vector<vector<int>> map2 = MakeMoveMap(map, startPositions[0].first, startPositions[0].second);
    vector<vector<int>> map3 = MakeMoveMap(map, startPositions[1].first, startPositions[1].second);

    int minCost = INVALID_COST;
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            if(map[y][x] != '*')
            {
                minCost = min(minCost, map1[y][x]+map2[y][x]+map3[y][x]-(map[y][x]=='#'?2:0));
            }
        }
    }
    return minCost;
}

int main()
{
    int testCnt;
    cin >> testCnt;
    vector<int> result;
    for(int i=0;i<testCnt;i++)
    {
        cin >> h >> w;
        h+=2;
        w+=2;
        vector<vector<char>> map(h);
        for(int y=0;y<h;y++)
        {
            map[y].resize(w);
            for(int x=0;x<w;x++)
            {
                if(y==0 || x==0 || y==h-1||x==w-1) map[y][x] = '.';                
                else cin >> map[y][x];
            }
        }
        result.push_back(GetMinOpenDoor(map));
    }
    for(int val : result)
    {
        cout << val << endl;
    }
}