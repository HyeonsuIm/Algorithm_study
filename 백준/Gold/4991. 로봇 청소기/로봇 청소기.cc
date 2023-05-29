#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
int w, h;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

vector<pair<int,int>> SummarizeMap(vector<string>& map, int& rStartIdx)
{
    vector<pair<int,int>> nodes;
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            if(map[y][x]=='*' || map[y][x] =='o')
            {
                nodes.push_back({y,x});
                if(map[y][x] == 'o')
                {
                    rStartIdx = nodes.size()-1;
                }
            }
        }
    }
    return nodes;
}

int CalculateRoute(vector<string>& map, std::pair<int,int>& start, std::pair<int,int> end)
{
    vector<vector<bool>> visited(h);
    for(int y=0;y<h;y++)
    {
        visited[y].assign(w, false);
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push({0, start.first, start.second});
    visited[start.first][start.second] = true;

    int result = -1;
    while(!pq.empty())
    {
        int cost = get<0>(pq.top());
        int y = get<1>(pq.top());
        int x = get<2>(pq.top());
        pq.pop();
        if( y == end.first && x== end.second)
        {
            result = cost;
            break;
        }

        for(int d=0;d<4;d++)
        {
            int nextY = y+dy[d];
            int nextX = x+dx[d];
            if( nextY >= 0 && nextY < h && nextX >= 0 && nextX < w)
            {
                if(!visited[nextY][nextX] && map[nextY][nextX] != 'x')
                {
                    pq.push({cost+1, nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }
        }
    }
    return result;
}

vector<vector<pair<int,int>>> MakeGraph(vector<string>& map, vector<pair<int,int>>& dirtyPoints)
{
    vector<vector<pair<int,int>>> graph(dirtyPoints.size());
    for(int i=0;i<dirtyPoints.size();i++)
    {
        for(int j=i+1;j<dirtyPoints.size();j++)
        {
            int cost = CalculateRoute(map, dirtyPoints[i], dirtyPoints[j]);
            graph[i].push_back({j, cost});
            graph[j].push_back({i, cost});
        }
    }
    return graph;
}

int dfs_impl(vector<vector<pair<int,int>>>& graph, vector<bool>& visited, int idx, int depth)
{
    if( depth == graph.size()-1)
    {
        return 0;
    }
    int finalCost = 0x7fffffff;
    for(int i=0;i<graph[idx].size();i++)
    {
        int next = graph[idx][i].first;
        if(!visited[next] && graph[idx][i].second != -1)
        {
            visited[next] = true;
            int cost = dfs_impl(graph, visited, next, depth+1);
            if( cost != -1 )
            {
                finalCost = min(finalCost, cost+graph[idx][i].second);
            }
            visited[next] = false;
        }
    }
    if( finalCost == 0x7fffffff)
    {
        return -1;
    }
    return finalCost;
}

int dfs(vector<vector<pair<int,int>>>& graph, int startIdx)
{
    vector<bool> visited(graph.size(), false);
    visited[startIdx] = true;
    return dfs_impl(graph, visited, startIdx, 0);
}

int main()
{ 
    
    while(true)
    {
        cin >> w >> h;
        if( w==0&&h==0)
        {
            break;
        }
        vector<string> map(h);
        for(int y=0;y<h;y++)
        {
            cin >> map[y];
        }

        int startIdx;
        vector<pair<int,int>> dirtyPoints = SummarizeMap(map, startIdx);
        vector<vector<pair<int,int>>> graph = MakeGraph(map, dirtyPoints);

        cout << dfs(graph, startIdx) << endl;
    }
}