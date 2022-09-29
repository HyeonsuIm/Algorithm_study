#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> val(n);
    for(int i=0;i<n;i++)
    {
        cin >> val[i];
    }
    int biggestSqure =0;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            if(val[j][i] == '1')
            {
                dp[j+1][i+1] = min(min(dp[j][i+1], dp[j+1][i]), dp[j][i])+1;
            }
            else
            {
                dp[j+1][i+1] = 0;
            }
            biggestSqure = max(dp[j+1][i+1], biggestSqure);
        }
    }
    cout << biggestSqure * biggestSqure;
}