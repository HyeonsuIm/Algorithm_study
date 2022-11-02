#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

#define MAP_SIZE 5
#define MEMBER_CNT 7
#define S_MEMBER_CNT 4

bool visited[MAP_SIZE][MAP_SIZE];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool CheckValidPositions(const vector<vector<bool>>& selectList)
{
    int startX = 0;
    int startY = 0;
    bool isFound = false;
    for(startY=0;startY<MAP_SIZE;startY++)
    {
        for(startX=0;startX<MAP_SIZE;startX++)
        {
            if( selectList[startY][startX] )
            {
                isFound = true;
                break;
            }
        }
        if(isFound) break;
    }

    queue<pair<int,int>> q;
    q.push({startY,startX});
    memset(visited, 0, sizeof(visited));
    visited[startY][startX]=true;
    int searchCnt = 0;
    while(!q.empty())
    {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        searchCnt+=1;
        for(int i=0;i<4;i++)
        {
            if(currY+dy[i] < MAP_SIZE && currY+dy[i] >= 0 && currX+dx[i] < MAP_SIZE && currX+dx[i] >=0)
            {
                if( false == visited[currY+dy[i]][currX+dx[i]] && 
                    true == selectList[currY+dy[i]][currX+dx[i]] )
                {
                    q.push({currY+dy[i], currX+dx[i]});
                    visited[currY+dy[i]][currX+dx[i]] = true;
                }
            }
        }
    }
    if( searchCnt == 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dfs(vector<string>& map, int y, int x, vector<vector<bool>>& selectList, int remainSMemberCnt, int remainCnt)
{
    int result = 0;
    if( remainSMemberCnt > remainCnt )
    {
        return 0;
    }

    if(remainCnt == 0)
    {
        if(CheckValidPositions(selectList))
        {
            return 1;
        }
    }
    else
    {
        for(int i=y*MAP_SIZE+x;i<MAP_SIZE*MAP_SIZE;i++)
        {
            int nextY = i/MAP_SIZE;
            int nextX = i%MAP_SIZE;
            if(selectList[nextY][nextX])
            {
                continue;
            }

            int sMember = 0;
            if(map[nextY][nextX] == 'S')
            {
                sMember = 1;
            }
            selectList[nextY][nextX] = true;
            result += dfs(map, nextY, nextX, selectList, remainSMemberCnt - sMember, remainCnt-1);
            selectList[nextY][nextX] = false;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> map(MAP_SIZE);
    for(int i=0;i<MAP_SIZE;i++)
    {
        cin >> map[i];
    }

    vector<vector<bool>> selectList(MAP_SIZE);
    for(vector<bool>& selectRow : selectList)
    {
        selectRow.resize(MAP_SIZE, false);
    }
    cout << dfs(map, 0, 0, selectList, S_MEMBER_CNT, MEMBER_CNT);
}