#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void PhaseAlignment(
    vector<vector<int>>& graph, 
    vector<int>& inboundCnt,
    vector<int>& result)
{
    queue<int> q;
    for(int i=0;i<inboundCnt.size();i++)
    {
        if(inboundCnt[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        result.push_back(top);
        vector<int>& nextNodes = graph[top];
        for(int nextNode : nextNodes)
        {
            inboundCnt[nextNode]--;
            if(inboundCnt[nextNode]==0)
            {
                q.push(nextNode);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<int> inboundCnt(N, 0);
    for(int i=0;i<M;i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from-1].push_back(to-1);
        inboundCnt[to-1]++;
    }

    vector<int> result;
    PhaseAlignment(graph, inboundCnt, result);
    for(int order : result)
    {
        cout << order+1 << " ";
    }
}