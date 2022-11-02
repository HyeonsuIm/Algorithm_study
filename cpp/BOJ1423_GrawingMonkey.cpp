#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long charterStatus[101][50];
long long dp[101];

int main()
{
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin >> charterStatus[0][i];
    }

    vector<int> powerSum(N);
    vector<long long> powers(N);
    for(int i=0;i<N;i++)
    {
        cin >> powers[i];
    }

    for(int i=0;i<N;i++)
    {
        dp[0] += powers[i] * charterStatus[0][i];
    }

    int days;
    cin >> days;

    for(int i=1;i<=days;i++)
    {
        for(int j=0;j<i;j++)
        {
            int diff = i-j;
            long long bestScore = 0;
            int selectCharter = 0;
            for(int k=0;k<N-diff;k++)
            {
                if( charterStatus[j][k] > 0 )
                {
                    if( bestScore < powers[k+diff] - powers[k] )
                    {
                        bestScore = powers[k+diff] - powers[k];
                        selectCharter = k;
                    }
                }
            }
            
            if( dp[i] < dp[j]+bestScore && bestScore != 0)
            {
                for(int k=0;k<N;k++)
                {
                    charterStatus[i][k] = charterStatus[j][k];
                }
                dp[i] = dp[j]+bestScore;
                charterStatus[i][selectCharter]-=1;
                charterStatus[i][selectCharter+diff]+=1;
            }
        }
    }
    cout << *max_element(dp, dp+days+1);
}