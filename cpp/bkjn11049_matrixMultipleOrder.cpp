#include <iostream>
#include <vector>

using namespace std;
int dp[501][501];

int getBestCnt(vector<pair<int,int>>& valList, int start, int end)
{
    if(start==end)
    {
        return 0;
    }
    else if(dp[start][end] != 0)
    {
        return dp[start][end];
    }
    else if(start+1 == end)
    {
        dp[start][end] = valList[start].first * valList[start].second * valList[end].second;
    }
    else
    {
        dp[start][end] = getBestCnt(valList, start, start) + getBestCnt(valList, start+1,end) + valList[start].first * valList[start].second * valList[end].second;
        for(int mid = start+1;mid<end;mid++)
        {
            dp[start][end] = min(dp[start][end], getBestCnt(valList, start, mid) + getBestCnt(valList, mid+1,end) + valList[start].first * valList[mid].second * valList[end].second);
        }
    }
    return dp[start][end];
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> valList(N);

    for(int i=0;i<N;i++)
    {
        dp[i][i] = 0;
        cin >> valList[i].first;
        cin >> valList[i].second;
    }

    cout << getBestCnt(valList, 0, N-1);
}