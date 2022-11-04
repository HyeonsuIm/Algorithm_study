#include <iostream>
#include <vector>

using namespace std;

pair<int, int> parents[100001];
bool used[100001];

void MakeTree(vector<vector<int>>& tree, vector<vector<int>>& connNodes, vector<vector<int>>& connNodes_reverse, int node)
{
    vector<int> nextNodes;
    for( int nextNode : connNodes[node] )
    {
        if(!used[nextNode])
        {
            nextNodes.push_back(nextNode);
            tree[node].push_back(nextNode);
            used[nextNode]=true;
        }
    }

    for( int nextNode : connNodes_reverse[node] )
    {
        if(!used[nextNode])
        {
            nextNodes.push_back(nextNode);
            tree[node].push_back(nextNode);
            used[nextNode]=true;
        }
    }

    for(int nextNode : nextNodes)
    {
        MakeTree(tree, connNodes, connNodes_reverse, nextNode);
    }
}

void MakeTree(vector<vector<int>>& tree, vector<vector<int>>& connNodes, vector<vector<int>>& connNodes_reverse)
{
    used[1] = true;
    MakeTree(tree, connNodes, connNodes_reverse, 1);
}

void MakeParents(vector<vector<int>>& tree, int parent, int node, int depth)
{
    parents[node].first = parent;
    parents[node].second = depth;
    for(int nextNode : tree[node])
    {
        MakeParents(tree, node, nextNode, depth+1);
    }
}

int GetCommonParent(int node1, int node2)
{
    if(node1 == node2)
    {
        return node1;
    }

    if( parents[node1].second < parents[node2].second )
    {
        return GetCommonParent(node1, parents[node2].first);
    }
    else if(parents[node1].second > parents[node2].second )
    {
        return GetCommonParent(parents[node1].first, node2);
    }
    else
    {
        return GetCommonParent(parents[node1].first, parents[node2].first);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> connNodes(N+1);
    vector<vector<int>> connNodes_reverse(N+1);
    for(int i=0;i<N-1;i++)
    {
        int from, to;
        cin >> from >> to;
        connNodes[from].push_back(to);
        connNodes_reverse[to].push_back(from);
    }
    vector<vector<int>> tree(N+1);
    MakeTree(tree, connNodes, connNodes_reverse);
    MakeParents(tree, 0, 1, 0);

    int M;
    cin >> M;
    for(int i=0;i<M;i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        cout << GetCommonParent(node1, node2) << endl;
    }
}