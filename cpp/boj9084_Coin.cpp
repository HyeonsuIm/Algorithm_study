#include <iostream>
#include <vector>

using namespace std;

int SolveProblem(int N, int M, vector<int>& coins)
{
    vector<int> dp(M+1);
    dp[0] = 1;
    for(int j=0;j<coins.size();j++)
    {
        for(int i=coins[j];i<=M;i++)
        {
            dp[i] += dp[i-coins[j]];
        }
    }
    return dp[M];
}

int main()
{
    int T, N, M;
    cin >> T;
    vector<int> results(T);
    for(int i=0;i<T;i++)
    {
        cin >> N;
        vector<int> coins(N);
        for(int j=0;j<N;j++)
        {
            cin >> coins[j];
        }
        cin >> M;
        results[i] = SolveProblem(N, M, coins);
    }

    for(int i=0;i<T;i++)
    {
        cout << results[i] << endl;
    }
}