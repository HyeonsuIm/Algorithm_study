#include <iostream>

using namespace std;

int dp[31];

int main()
{
    int N;
    cin >> N;
    dp[2] = 3;
    dp[4] = 11;
    for(int i=6;i<=N;i+=2)
    {
        dp[i] = dp[i-2]*3;
        for(int j=i-4;j>=2;j-=2)
        {
            dp[i] += dp[j]*2;
        }
        dp[i]+=2;
    }
    cout << dp[N];
}