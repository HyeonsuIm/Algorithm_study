#include <iostream>
#include <vector>

using namespace std;

int dp[500][500];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int M, N;

int GetRouteCount(int y, int x, vector<vector<int>>& map, int val)
{
    if( y >= M || x >= N || y < 0 || x < 0)
    {
        return 0;
    }
    if( val <= map[y][x] || dp[y][x] == -1)
    {
        return 0;
    }
    
    if(dp[y][x] != 0)
    {
        return dp[y][x];
    }

    int result=0;
    for(int i=0;i<4;i++)
    {
        result += GetRouteCount(y+dy[i], x+dx[i], map, map[y][x]);
    }
    if( result == 0)
    {
        dp[y][x] = -1;
    }
    else
    {
        dp[y][x] = result;
    }
    return result;
}

int main()
{
    cin >> M >> N;
    dp[M-1][N-1] = 1;
    vector<vector<int>> map(M);
    for(int i=0;i<M;i++)
    {
        map[i].assign(N, 0);
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
        }
    }

    cout << GetRouteCount(0,0, map, 100001);
}