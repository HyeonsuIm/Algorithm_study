#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501];

int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> lineList(N);
    for(int i=0;i<N;i++)
    {
        cin >> lineList[i].first >>lineList[i].second;
    }

    sort(lineList.begin(), lineList.end());
    int maximumIncreaseSubsequence=0;
    for(int i=0;i<N;i++)
    {
        int j = 0;
        for(;j<maximumIncreaseSubsequence;j++)
        {
            if(dp[j] >= lineList[i].second)
            {
                dp[j] = lineList[i].second;
                break;
            }
        }

        if( j == maximumIncreaseSubsequence)
        {
            dp[maximumIncreaseSubsequence++] = lineList[i].second;
        }
    }

    cout << N-maximumIncreaseSubsequence;
}