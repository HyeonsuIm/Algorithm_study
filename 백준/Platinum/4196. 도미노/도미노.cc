#include <iostream>
#include <vector>
#include <memory.h>

#define MAX_NODE 100000

bool visited[MAX_NODE];

using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<int>& stack, bool* isVisited)
{
    isVisited[node] = true;
    for(int nextNode : graph[node])
    {
        if(!isVisited[nextNode])
            dfs(graph,nextNode,stack,isVisited);
    }
    stack.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin >> T;


    for(int i=0;i<T;i++)
    {
        memset(visited, 0, sizeof(bool)*MAX_NODE);
        int N, M;
        cin >> N >> M;
        vector<vector<int>> graph(N), graph_r(N);
        for(int j=0;j<M;j++)
        {
            int x,y;
            cin >> x >> y;
            graph[x-1].push_back(y-1);
            graph_r[y-1].push_back(x-1);
        }

        vector<int> stack;
        for(int j=0;j<N;j++)
        {
            if(!visited[j])
            {
                dfs(graph, j, stack, visited);
            }
        }

        memset(visited, 0, sizeof(bool)*MAX_NODE);
        vector<vector<int>> scc;
        vector<int> sccNumber4Node(N);
        for(int j=stack.size()-1;j>=0;j--)
        {
            vector<int> cc;
            if(!visited[stack[j]])
            {
                dfs(graph_r, stack[j], cc, visited);
                for(int val : cc)
                {
                    sccNumber4Node[val] = scc.size();
                }
                scc.push_back(cc);
            }
        }

        vector<int> inbounds(scc.size(), 0);
        for(int j=0;j<scc.size();j++)
        {
            for(int node : scc[j])
            {
                for( int prevNode : graph_r[node])
                {
                    if( sccNumber4Node[prevNode] != j ) inbounds[j]++;
                }
            }
        }

        int count = 0;
        for(int val : inbounds)
        {
            if(val == 0) count++;
        }
        cout << count << endl;
    }
}