#include <iostream>

using namespace std;

int dp[201][201];

int combination(int n, int r)
{
    if(n==r || r == 0)
    {
        return 1;
    }
    if(dp[n][r] == 0)
    {
        dp[n][r] = combination(n-1, r-1) + combination(n-1,r);
        if( dp[n][r] > 1000000000 )
        {
            dp[n][r] = 1000000001;
        }
    }
    return dp[n][r];
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    int cnt = combination(N+M, N);
    if( cnt < K )
    {
        cout << -1;
    }
    else
    {
        string result;
        while(N > 0 && M>0)
        {
            int cnt = combination(N+M-1, N-1);
            if( K > cnt )
            {
                result += 'z';
                K -= cnt;
                M--;
            }
            else
            {
                result += 'a';
                N--;
            }
        }

        for(int i=0;i<N;i++)
        {
            result += 'a';
        }

        for(int i=0;i<M;i++)
        {
            result += 'z';
        }
        cout << result;
    }
}