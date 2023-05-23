#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int W, H;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<char>> MakeMap(vector<vector<int>>& clustorMap)
{
    vector<vector<char>> map(H);
    for(int y=0;y<H;y++)
    {
        map[y].resize(W);
        for(int x=0;x<W;x++)
        {
            if( clustorMap[y][x] == 0 )
            {
                map[y][x] = '.';
            }
            else
            {
                map[y][x] = 'x';
            }
        }
    }
    return map;
}

void ClustorDown(vector<vector<char>>& map, vector<vector<int>>& clustorMap, int val)
{
    bool isSuccess = true;
    while(isSuccess)
    {
        vector<vector<int>> downClustorMap = clustorMap;
        for(int y=1;y<H;y++)
        {
            for(int x=0;x<W;x++)
            {
                if( downClustorMap[y][x] == val )
                {
                    if( downClustorMap[y-1][x] == 0 )
                    {
                        downClustorMap[y-1][x] = val;
                        downClustorMap[y][x] = 0;
                    }
                    else
                    {
                        isSuccess = false;
                        break;
                    }
                }
            }
            if(!isSuccess) break;
        }
        if(isSuccess)
        {
            clustorMap = downClustorMap;
        }
    }

    map = MakeMap(clustorMap);
}

void MakeClustor(vector<vector<char>>& map, vector<vector<int>>& clustorMap, int y, int x, int val)
{
    queue<pair<int,int>> q;
    q.push({y,x});

    clustorMap[y][x] = val;
    while(!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int d=0;d<4;d++)
        {
            int nextY = y+dy[d];
            int nextX = x+dx[d];
            if(nextY >= 0 && nextY < H && nextX >= 0 && nextX < W)
            {
                if(map[nextY][nextX] == 'x' && clustorMap[nextY][nextX] == 0)
                {
                    clustorMap[nextY][nextX] = val;
                    q.push({nextY,nextX});
                }
            }
        }
    }
}

void UpdateMap(vector<vector<char>>& map)
{
    vector<vector<int>> clustorMap(H);
    for(int i=0;i<H;i++)
    {
        clustorMap[i].assign(W, 0);
    }

    int val = 1;
    for(int y=0;y<H;y++)
    {
        for(int x=0;x<W;x++)
        {
            if(map[y][x] == 'x' && clustorMap[y][x] == 0)
            {
                MakeClustor(map, clustorMap, y, x, val);
                if( y != 0 )
                {
                    ClustorDown(map, clustorMap, val);
                }
                val+=1;
            }
        }
    }
}

int main()
{
    cin >> H >> W;

    vector<vector<char>> map(H);
    for(int i=H-1;i>=0;i--)
    {
        map[i].resize(W);
        for(int j=0;j<W;j++) cin >> map[i][j];
    }

    int cnt;
    cin >> cnt;

    for(int i=0;i<cnt;i++)
    {
        int throwHeight;
        cin >> throwHeight;

        int start = 0;
        int end = W;
        int next = 1;
        if(i%2 != 0)
        {
            start = W-1;
            end = -1;
            next = -1;
        }

        for(int i=start;i!=end;i+=next)
        {
            if( map[throwHeight-1][i] == 'x' )
            {
                map[throwHeight-1][i] = '.';
                break;
            }
        }
        UpdateMap(map);
    }
    for(int y=H-1;y>=0;y--)
    {
        for(int x=0;x<W;x++)
        {
            cout << map[y][x];
        }
        cout << endl;
    }
    return 0;
}