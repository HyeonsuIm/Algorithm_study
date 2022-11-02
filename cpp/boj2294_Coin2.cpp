#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][100001];

#define INVALID_INT 0x7fffffff

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
    }
    
    coins.erase(unique(coins.begin(), coins.end()), coins.end());
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(coins.size()+1);
    for(int i=0;i<=coins.size();i++)
    {
        dp[i].assign(k+1, INVALID_INT);
        dp[i][0] = 0;
    }
    for(int i=0;i<coins.size();i++)
    {
        for(int j=1;j<=k;j++)
        {
            if( j < coins[i])
            {
                dp[i+1][j] = dp[i][j];
            }
            else
            {
                if( dp[i+1][j-coins[i]] != INVALID_INT)
                {
                    dp[i+1][j] = min(dp[i][j], dp[i+1][j-coins[i]]+1);
                }
                else
                {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
    }
    if( dp[coins.size()][k] == INVALID_INT )
    {
        cout << -1;
    }
    else
    {
        cout << dp[coins.size()][k];
    }
}