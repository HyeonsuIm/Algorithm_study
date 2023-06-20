#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;

vector<vector<int>> map;
vector<int> areas;

int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

void Search(int y, int x)
{
    int dataIdx = areas.size();
    areas.push_back(0);

    queue<pair<int,int>> q;
    q.push({y,x});
    map[y][x] = dataIdx;
    areas[dataIdx]++;

    while(!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int d=0;d<4;d++)
        {
            int nextY = y+dy[d];
            int nextX = x+dx[d];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
            if( map[nextY][nextX] == -1 )
            {
                q.push({nextY,nextX});
                map[nextY][nextX] = dataIdx;
                areas[dataIdx]++;
            }
        }
    }
}

int GetSize(int y, int x)
{
    vector<int> usedArea;
    int size = 1;
    for(int d=0;d<4;d++)
    {
        int nextY = y+dy[d];
        int nextX = x+dx[d];
        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
        if( map[nextY][nextX] != -2 )
        {
            int areaIdx = map[nextY][nextX];
            if( usedArea.end() == std::find(usedArea.begin(), usedArea.end(), areaIdx ) )
            {
                usedArea.push_back(areaIdx);
                size += areas[areaIdx];
            }
        }
    }
    return size;
}

int main()
{
    cin >> N >> M;
    map.assign(N, vector<int>(M, 0));
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<M;x++) 
        {
            char val;
            cin >> val;
            if( val == '0') map[y][x] = -1;
            else map[y][x] = -2;
            
        }
    }

    for(int y=0;y<N;y++)
    {
        for(int x=0;x<M;x++)
        {
            if( -1 == map[y][x] )
            {
                Search(y, x);
            }
        }
    }

    for(int y=0;y<N;y++)
    {
        for(int x=0;x<M;x++)
        {
            if( -2 == map[y][x] ) cout << GetSize(y, x) % 10;
            else cout << 0;
        }
        cout << endl;
    }
}