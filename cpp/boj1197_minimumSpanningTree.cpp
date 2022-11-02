#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
using namespace std;

long long GetMinimumSpanningWeight(
    vector<vector<pair<int,int>>>& graph)
{
    long long totalWeight = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    bool* isUsedNode = new bool[graph.size()];
    memset(isUsedNode, 0, sizeof(bool)*graph.size());
    pq.push(make_pair(0, 0));

    while(pq.empty() == false)
    {
        int weight = pq.top().first;
        int position = pq.top().second;
        pq.pop();
        if( isUsedNode[position] == true )
        {
            continue;
        }
        totalWeight += weight;
        isUsedNode[position]=true;
        
        vector<pair<int,int>>& edges = graph[position];
        for(const pair<int,int>& edge : edges)
        {
            if( isUsedNode[edge.first] == false )
            {
                pq.push(make_pair(edge.second,edge.first));
            }
        }         
    }
    delete[] isUsedNode;
    return static_cast<int>(totalWeight);
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int,int>>> graph(V);
    for(int i=0;i<E;i++)
    {
        int from,to,weight;
        cin >> from >> to >> weight;
        graph[from-1].push_back(make_pair(to-1, weight));
        graph[to-1].push_back(make_pair(from-1, weight));
    }
    cout << GetMinimumSpanningWeight(graph);
}