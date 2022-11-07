#include <iostream>
#include <vector>
using namespace std;
int dp[10001];

int main()
{
    int N;
    cin >> N;
    vector<int> wineList(N);
    for(int i=0;i<N;i++)
    {
        cin >> wineList[i];
    }

    for(int i=0;i<N;i++)
    {
        if( i < 2)
        {
            dp[i+1] = dp[i] + wineList[i];
        }
        else
        {
            dp[i+1] = max(dp[i], max(dp[i-1] + wineList[i], dp[i-2]+wineList[i-1]+wineList[i]));
        }
    }
    cout << dp[N];
}