#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_COST 10000

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> appList(N);
    for(int i=0;i<N;i++) cin >> appList[i].first;
    for(int i=0;i<N;i++) cin >> appList[i].second;

    vector<vector<int>> dp(N+1);
    dp[0].assign(MAX_COST+1, -1);
    dp[0][0] = 0;
    for(int i=0;i<N;i++)
    {
        dp[i+1].assign(MAX_COST+1, -1);
        for(int j=0;j<=MAX_COST;j++)
        {
            if(j >= appList[i].second && dp[i][j-appList[i].second] != -1)
            {
                dp[i+1][j] = max(dp[i][j], dp[i][j-appList[i].second]+appList[i].first);
            }
            else
            {
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    for(int i=0;i<=MAX_COST;i++)
    {
        if( dp[N][i] >= M )
        {
            cout << i;
            break;
        }
    }
    return 0;
}