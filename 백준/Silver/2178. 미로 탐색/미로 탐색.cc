#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool visited[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int N, M;

int bfs(vector<string>& map)
{
    queue<tuple<int, int,int>> q;
    q.push({1, 0,0});
    visited[0][0] = true;

    while(!q.empty())
    {
        int cost = get<0>(q.front());
        int y = get<1>(q.front());
        int x = get<2>(q.front());
        q.pop();
        if(y == N-1&& x == M-1)
        {
            return cost;
        }

        for(int i=0;i<4;i++)
        {
            if( y+dy[i] < N && y+dy[i] >= 0 && x+dx[i] < M && x+dx[i] >= 0)
            {
                if(!visited[y+dy[i]][x+dx[i]] &&
                    '1' == map[y+dy[i]][x+dx[i]])
                {
                    q.push({cost+1, y+dy[i], x+dx[i]});
                    visited[y+dy[i]][x+dx[i]] = true;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<string> map(N);
    for(int i=0;i<N;i++)
    {
        cin >> map[i];
    }

    cout << bfs(map);
}