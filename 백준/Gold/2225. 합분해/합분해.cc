#include <iostream>
using namespace std;

int dp[201][201];

int main()
{
    int N, K;
    cin >> N >> K;

    for(int i=1;i<=K;i++) dp[0][i] = 1;
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=N;j++) dp[j][i] = (dp[j][i-1]+dp[j-1][i]) % 1000000000;
    }
    cout << dp[N][K];
}