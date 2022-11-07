#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> items(N);
    for(int i=0;i<N;i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=K;j++)
        {
            if(j >= items[i].first)
                dp[i+1][j] = max(dp[i][j-items[i].first]+items[i].second, dp[i][j]);
            else
                dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[N][K];
}