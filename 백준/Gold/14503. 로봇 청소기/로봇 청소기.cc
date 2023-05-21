#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int N, M;
int currX,currY,currD;
vector<vector<int>> map;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int main()
{
    cin >> N >> M;
    cin >> currY >> currX >> currD;
    map.resize(N);
    for(int y=0;y<N;y++)
    {
        map[y].resize(M);
        for(int x=0;x<M;x++) cin >> map[y][x];
    }

    int cleanCnt=0;
    while(true)
    {
        //valid check
        if(map[currY][currX] == 0)
        {
            cleanCnt++;
            map[currY][currX] = 2;
        }
        else if(map[currY][currX]==1)
        {
            break;
        }

        // around check
        bool valid=false;
        for(int d=0;d<4;d++)
        {
            currD = (currD+3)%4;
            if(map[currY+dy[currD]][currX+dx[currD]] == 0)
            {
                currX += dx[currD];
                currY += dy[currD];
                valid = true;
                break;
            }
        }

        // back check
        if(!valid)
        {
            currX-=dx[currD];
            currY-=dy[currD];
        }
    }
    cout << cleanCnt;
}