#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void nodeOrdering(const vector<int>& buildingBuildTime, const vector<vector<int>>& graph, vector<int> inboundEdgeCnts, vector<int>& buildingMaxTime)
{
    int currentTime = 0;
    queue<int> q;

    // 진입 edge가 없는 경우 queue에 삽입
    int listSize = inboundEdgeCnts.size();
    for( int i=0;i<listSize;i++)
    {
        if(inboundEdgeCnts[i] == 0)
        {
            buildingMaxTime[i] = buildingBuildTime[i];
            q.push(i);
        }
    }

    // queue가 빌 때까지 반복작업
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

    // 그래프를 구성하고, 노드로 진입하는 edge수를 센다.
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
    // node들에 대한 반복 작업
    nodeOrdering(buildingBuildTime, graph, inboundEdgeCnt, buildingMaxTime);
    
    // 목표의 최대 시간 반환
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