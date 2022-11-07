#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int dp[1001][1001];
int jobCnt;
vector<pair<int,int>> jobs[2];

int GetDist(vector<pair<int,int>>& job, int i, int j)
{
    return abs(job[i].first - job[j].first) + abs(job[i].second-job[j].second);
}


int GetMinDist(int i, int j)
{
    if(i == jobCnt || j == jobCnt)
    {
        return 0;
    }

    if( dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int next = max(i,j)+1;
    int result1 = GetMinDist(next, j);
    int result2 = GetMinDist(i, next);

    int dist1 = result1 + GetDist(jobs[0], i, next);
    int dist2 = result2 + GetDist(jobs[1], j, next);

    return dp[i][j] = min(dist1, dist2);
}

void Print(int i, int j)
{
    if(i == jobCnt || j == jobCnt)
    {
        return;
    }

    int next = max(i,j)+1;
    int result1 = GetMinDist(next, j);
    int result2 = GetMinDist(i, next);

    int dist1 = result1 + GetDist(jobs[0], i, next);
    int dist2 = result2 + GetDist(jobs[1], j, next);

    if(dist1 > dist2)
    {
        cout << 2 << endl;
        Print(i, next);
    }
    else
    {
        cout << 1 << endl;
        Print(next, j);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int N;
    cin >> N >> jobCnt;
    jobs[0].resize(jobCnt+1);
    jobs[1].resize(jobCnt+1);
    jobs[0][0].first = jobs[0][0].second = 0;
    jobs[1][0].first = jobs[1][0].second = N-1;
    for(int i=1;i<=jobCnt;i++)
    {
        int x, y;
        cin >> x >> y;
        jobs[0][i].first = x-1;
        jobs[0][i].second = y-1;

        jobs[1][i].first = x-1;
        jobs[1][i].second = y-1;
    }

    cout << GetMinDist(0,0) << endl;
    Print(0,0);
}