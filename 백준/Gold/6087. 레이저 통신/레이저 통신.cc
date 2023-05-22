#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<char>> map;
vector<vector<int>> costs;
int W, H;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int bfs(pair<int,int>& start, pair<int,int>& dest)
{
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push({-1, start.first, start.second});
    while(!pq.empty())
    {
        int cost = get<0>(pq.top());
        int y = get<1>(pq.top());
        int x = get<2>(pq.top());
        pq.pop();
        if(y==dest.first && x==dest.second)
        {
            return cost;
        }

        for(int d=0;d<4;d++)
        {
            int nextX = x + dx[d];
            int nextY = y + dy[d];
            while(nextX >= 0 && nextY >= 0 && nextX < W && nextY < H)
            {
                if(map[nextY][nextX] == '.' || map[nextY][nextX] == 'C')
                {
                    if(costs[nextY][nextX] > cost+1)
                    {
                        pq.push({cost+1, nextY, nextX});
                        costs[nextY][nextX] = cost+1;
                    }
                    nextX = nextX + dx[d];
                    nextY = nextY + dy[d];
                }
                else break;
            }
        }

    }
    return 0;
}

int main()
{
    cin >> W >> H;
    map.resize(H);
    costs.resize(H);

    int pointCnt = 0;
    pair<int,int> points[2];
    for(int y=0;y<H;y++)
    {
        map[y].resize(W);
        costs[y].assign(W, 0x7fffffff);
        for(int x=0;x<W;x++)
        {
            cin >> map[y][x];
            if(map[y][x] == 'C')
            {
                points[pointCnt].first = y;
                points[pointCnt++].second = x;
            }
        }
    }

    printf("%d", bfs(points[0], points[1]));
}