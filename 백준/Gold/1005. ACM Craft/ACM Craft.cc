#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

void bfs(const vector<int>& buildingBuildTime, const vector<vector<int>>& graph, vector<int> inboundEdgeCnts, vector<int>& buildingMaxTime)
{
    int currentTime = 0;
    queue<int> q;
    int listSize = inboundEdgeCnts.size();
    for( int i=0;i<listSize;i++)
    {
        if(inboundEdgeCnts[i] == 0)
        {
            buildingMaxTime[i] = buildingBuildTime[i];
            q.push(i);
        }
    }

    while(false == q.empty())
    {
        int node = q.front();
        q.pop();

        const vector<int>& nextNodes = graph[node];
        for(int nextNode : nextNodes)
        {
            buildingMaxTime[nextNode] = max(buildingBuildTime[nextNode] + buildingMaxTime[node], buildingMaxTime[nextNode]);
            inboundEdgeCnts[nextNode] -= 1;
            if(inboundEdgeCnts[nextNode]==0)
            {
                q.push(nextNode);
            }
        }
    }
}


int PlayGame()
{
    int buildingCnt, ruleCnt;
    cin >> buildingCnt >> ruleCnt;
    vector<int> buildingBuildTime(buildingCnt);
    vector<vector<int>> graph(buildingCnt);
    vector<int> inboundEdgeCnt(buildingCnt);
    for(int i=0;i<buildingCnt;i++)
    {
        int time;
        cin >> time;
        buildingBuildTime[i] = time;
    }

    for(int i=0;i<ruleCnt;i++)
    {
        int buildOrderFrom, buildOrderTo;
        cin >> buildOrderFrom >> buildOrderTo;
        graph[buildOrderFrom-1].push_back(buildOrderTo-1);
        inboundEdgeCnt[buildOrderTo-1]+=1;
    }
    int goal;
    cin >> goal;
    vector<int> buildingMaxTime(buildingCnt);
    bfs(buildingBuildTime, graph, inboundEdgeCnt, buildingMaxTime);
    
    return buildingMaxTime[goal-1];
}

int main()
{
    int testCnt;
    cin >> testCnt;
    for( int i=0;i<testCnt;i++)
    {
        printf("%d\n",PlayGame());
    }
}