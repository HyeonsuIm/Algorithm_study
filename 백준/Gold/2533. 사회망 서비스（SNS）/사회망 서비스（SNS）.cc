#include <iostream>
#include <vector>
using namespace std;

#define EARLY_ADAPTOR 0
#define NOT_EARLY_ADAPTOR 1

int dp[1000001][2];
bool visited[1000001];

void MakeTree(vector<vector<int>>& tree, const vector<vector<int>>& edges, int node)
{
    visited[node] = true;
    for(int nextNode : edges[node])
    {
        if(visited[nextNode] == true ) continue;

        tree[node].push_back(nextNode);
        MakeTree(tree, edges, nextNode);
    }
}

int MakeMinimumEarlyAdaptor(vector<vector<int>>& tree, int node, int earlyAdaptor)
{
    if(dp[node][earlyAdaptor] != 0)
    {
        return dp[node][earlyAdaptor];
    }

    int bestScore = 0;
    for(int nextNode : tree[node])
    {
        int score = MakeMinimumEarlyAdaptor(tree, nextNode, EARLY_ADAPTOR);
        if(earlyAdaptor == EARLY_ADAPTOR)
        {
            score = min(score, MakeMinimumEarlyAdaptor(tree, nextNode, NOT_EARLY_ADAPTOR));
        }
        bestScore += score;
    }

    if(earlyAdaptor == EARLY_ADAPTOR)
    {
        bestScore+=1;
    }
    dp[node][earlyAdaptor] = bestScore;
    return bestScore;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> edges(N);
    for(int i=0;i<N-1;i++)
    {
        int from, to;
        cin >> from >> to;
        edges[from-1].push_back(to-1);
        edges[to-1].push_back(from-1);
    }

    vector<vector<int>> tree(N);
    MakeTree(tree, edges, 0);

    MakeMinimumEarlyAdaptor(tree, 0, EARLY_ADAPTOR);
    MakeMinimumEarlyAdaptor(tree, 0, NOT_EARLY_ADAPTOR);
    cout << min(dp[0][0], dp[0][1]);
}