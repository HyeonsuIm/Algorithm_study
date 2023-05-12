#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
bool CheckValidWall(int x, int y)
{
    if(y == 0)
    {
        return true;
    }


    // 아래에 기둥이 있는 경우
    if(map[x][y-1] & 1)
    {
        return true;
    }

    // 좌/우에 막대가 없는 경우
    if(map[x][y] & 2)
    {
        return true;
    }
    else if(map[x-1][y] & 2)
    {
        return true;
    }

    return false;
}

bool CheckValidBoo(int x, int y)
{
    if(y==0)
    {
        return false;   
    }

    // 한쪽 끝이 기둥 위
    if(map[x][y-1] & 1)
    {
        return true;
    }

    if(map[x+1][y-1] & 1)
    {
        return true;
    }

    // 양쪽 모두 보
    if(map[x+1][y] & 2 && map[x-1][y] & 2)
    {
        return true;
    }

    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    map.resize(n+3);
    for(int i=0;i<n+3;i++)
    {
        map[i].resize(n+1, 0);
    }

    for(vector<int>& build : build_frame)
    {
        int x = build[0]+1;
        int y = build[1];
        int a = build[2];
        int b = build[3];

        if(a==0)
        {
            if(b==1)
            {
                if(CheckValidWall(x,y))
                {
                    map[x][y] |= 1;   
                }
            }
            else
            {
                if( map[x][y] & 1 )
                {
                    map[x][y] -= 1;
                    bool isValid = true;
                    if(map[x][y+1]&1)
                    {
                        isValid &= CheckValidWall(x, y+1);
                    }

                    if(map[x][y+1] & 2)
                    {
                        isValid &= CheckValidBoo(x,y+1);
                    }

                    if(map[x-1][y+1] & 2)
                    {
                        isValid &= CheckValidBoo(x-1,y+1);
                    }

                    if( false == isValid )
                    {
                        map[x][y] += 1;
                    }
                }
            }
        }
        else
        {
            if(b==1)
            {
                if(CheckValidBoo(x,y))
                {
                    map[x][y] |= 2;   
                }
            }
            else
            {
                if(map[x][y] & 2)
                {
                    map[x][y] -= 2;
                    bool isValid = true;
                    if(map[x][y]&1)
                    {
                        isValid &= CheckValidWall(x, y);
                    }

                    if(map[x+1][y] & 1)
                    {
                        isValid &= CheckValidWall(x+1,y);
                    }

                    if(map[x-1][y] & 2)
                    {
                        isValid &= CheckValidBoo(x-1,y);
                    }

                    if(map[x+1][y] & 2)
                    {
                        isValid &= CheckValidBoo(x+1,y);
                    }

                    if( false == isValid )
                    {
                        map[x][y] += 2;
                    }
                }
            }
        }
    }

    for(int x=1;x<n+2;x++)
    {
        for(int y=0;y<n+1;y++)
        {
            if (map[x][y] & 1)
            {
                vector<int> data;
                data.push_back(x-1);
                data.push_back(y);
                data.push_back(0);

                answer.push_back(data);
            }

            if(map[x][y] & 2)
            {
                vector<int> data;
                data.push_back(x-1);
                data.push_back(y);
                data.push_back(1);

                answer.push_back(data);
            }
        }
    }

    return answer;
}
