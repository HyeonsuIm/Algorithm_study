#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int n;
bool visited[100][100];
int minVal=200, maxVal=0;

struct node
{
    int y;
    int x;
};


bool Search(vector<vector<int>>& map, int diff)
{
    for(int i=minVal;i<=maxVal;i++)
    {
        if(map[0][0] > i+diff || map[0][0] < i)
        {
            continue;
        }
        memset(visited, 0, sizeof(visited));
        queue<node> q;
        q.push({0,0});
        
        while(!q.empty())
        {
            int y = q.front().y;
            int x = q.front().x;
            q.pop();
            if( y == n-1 && x == n-1)
            {
                return true;
            }

            for(int d=0;d<4;d++)
            {
                int nextY = y+dy[d];
                int nextX = x+dx[d];
                if(nextY < n && nextY>=0 && nextX < n && nextX>=0)
                {
                    if(i <= map[nextY][nextX] && i+diff >= map[nextY][nextX] && visited[nextY][nextX]==false)
                    {
                        q.push({nextY,nextX});
                        visited[nextY][nextX] = true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for(int y=0;y<n;y++)
    {
        for(int x=0;x<n;x++)
        {
            cin >> map[y][x];
            minVal = min(minVal, map[y][x]);
            maxVal = max(maxVal, map[y][x]);
        }
    }

    int start = 0, end = 200, mid;
    while(start!=end)
    {
        mid = (start+end)/2;
        if(Search(map, mid)) end = mid;
        else start = mid+1;
    }

    cout << end;
}