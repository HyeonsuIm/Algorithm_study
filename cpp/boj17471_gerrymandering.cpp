#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

vector<int> populations;
vector<vector<int>> graph;
bool visited[10];
int N;

#define INVALID_CNT 0x7fffffff

bool bfs(vector<int>& selected, int searchNumber)
{
    memset(visited, 0, sizeof(visited));
    int count=0;
    int lastIdx;
    for(int i=0;i<N;i++)
    {
        if(selected[i] == searchNumber)
        {
            count++;
            lastIdx = i;
        }
    }
    if( count == 0 )
    {
        return false;
    }

    queue<int> q;
    q.push(lastIdx);
    visited[lastIdx] = true;
    int visitCount = 0;
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        visitCount++;

        for(int nextNode : graph[idx])
        {
            if(!visited[nextNode] && selected[nextNode] == searchNumber)
            {
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }

    if( visitCount == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsValidCase(vector<int>& selected)
{
    return bfs(selected, 1) && bfs(selected, 2);
}

int GetDiff(vector<int>& selected)
{
    int count[2] = {0,0};
    for(int i=0;i<N;i++)
    {
        if(selected[i] == 1)
            count[0] += populations[i];
        else
            count[1] += populations[i];
    }
    return abs(count[0]-count[1]);
}

int dfs(vector<int>& selected,int count, int depth)
{
    if( depth == N)
    {
        if(IsValidCase(selected))
        {
            return GetDiff(selected);
        }
        else
        {
            return INVALID_CNT;
        }
    }
    else
    {
        int result = INVALID_CNT;
        if( count > 0)
        {
            selected[depth] = 1;
            result = dfs(selected, count-1,depth+1);
        }
        selected[depth] = 2;
        result = min(dfs(selected, count, depth+1),result);
        return result;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    populations.resize(N, 0);
    graph.resize(N);
    for(int i=0;i<N;i++)
    {
        cin >> populations[i];
    }

    for(int i=0;i<N;i++)
    {
        int count;
        cin >> count;
        for(int j=0;j<count;j++)
        {
            int nextNode;
            cin >> nextNode;
            graph[i].push_back(nextNode-1);
        }
    }

    int minDiff = INVALID_CNT;
    for(int i=1;i<N;i++)
    {
        vector<int> selected(N);
        minDiff = min(dfs(selected, i, 0), minDiff);
    }

    if( minDiff == INVALID_CNT)
    {
        cout << -1;
    }
    else
    {
        cout << minDiff;
    }
}