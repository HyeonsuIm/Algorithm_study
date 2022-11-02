#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001];
bool finished[10001];

void dfs(vector<vector<int>>& graph, vector<int>& stack, int node, bool* isVisited)
{
    isVisited[node] = true;
    for(int nextNode : graph[node])
    {
        if(!isVisited[nextNode])
        {
            dfs(graph, stack, nextNode, isVisited);
        }
    }
    stack.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V), graph_R(V);
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph_R[b-1].push_back(a-1);
    }

    vector<int> stack;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(graph, stack, i, visited);
        }
    }

    vector<int> stack_r;
    vector<vector<int>> result;
    for(int i=stack.size()-1;i>=0;i--)
    {
        if(!finished[stack[i]])
        {
            dfs(graph_R, stack_r, stack[i], finished);
            std::sort(stack_r.begin(), stack_r.end());
            result.push_back(stack_r);
            stack_r.clear();
        }
    }

    std::sort(result.begin(), result.end(), 
        [](vector<int>& rhs,vector<int>& lhs)->bool
        {
            return rhs[0]<lhs[0];
        });
    cout << result.size() << endl;
    for(vector<int>& row : result)
    {
        for(int val : row)
        {
            cout << val+1 << " ";
        }
        cout << -1 << endl;
    }
}