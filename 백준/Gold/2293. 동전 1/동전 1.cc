#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> coinList(n);
    for(int i=0;i<n;i++)
    {
        cin >> coinList[i];
    }
    sort(coinList.begin(), coinList.end());

    for(int i=0;i<n;i++)
    {
        dp[0] = 1;
        for(int j=coinList[i];j<=k;j++)
        {
            dp[j] += dp[j-coinList[i]];
        }
    }
    cout << dp[k];
}