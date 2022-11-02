#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dp[501];

int main()
{
    int N;
    cin >> N;
    vector<int> buildingTimeList(N);
    vector<int> buildingIncomeEdges(N);
    vector<vector<int>> graph(N);
    
    for(int i=0;i<N;i++)
    {
        cin >> buildingTimeList[i];
        int preBuilt;
        while(true)
        {
            cin >> preBuilt;
            if( preBuilt == -1)
            {
                break;
            }
            else
            {
                graph[preBuilt-1].push_back(i);
                buildingIncomeEdges[i]++;
            }
        }
    }

    queue<int> q;
    for(int i=0;i<N;i++)
    {
        if( buildingIncomeEdges[i] == 0 )
        {
            q.push(i);
            dp[i] = 0;
        }
    }

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(int next : graph[current])
        {
            dp[next] = max(dp[current]+buildingTimeList[current], dp[next]);
            buildingIncomeEdges[next]--;
            if( buildingIncomeEdges[next] == 0 )
            {
                q.push(next);
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        cout << dp[i] + buildingTimeList[i] << endl;
    }
}