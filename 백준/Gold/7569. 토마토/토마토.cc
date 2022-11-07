#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;

int moveX[6] = {1,-1,0,0,0,0};
int moveY[6] = {0,0,1,-1,0,0};
int moveH[6] = {0,0,0,0,1,-1};


int GetMaxCost(vector<vector<vector<int>>>& box)
{
    queue<pair<int,tuple<int,int,int>>> q;
    for(int h=0;h<H;h++)
    {
        for(int j=0;j<N;j++)
        {
            for(int i=0;i<M;i++)
            {
                if(box[h][j][i] == 1)
                {
                    q.push({0, {i,j,h}});
                }
            }
        }
    }

    int maxCost = 0;
    while(!q.empty())
    {
        int cost = q.front().first;
        tuple<int,int,int> position = q.front().second;
        q.pop();
        maxCost = max(cost, maxCost);

        int x = get<0>(position);
        int y = get<1>(position);
        int h = get<2>(position);
        for(int i=0;i<6;i++)
        {
            int nextX = x+moveX[i];
            int nextY = y+moveY[i];
            int nextH = h+moveH[i];
            if( nextX >= M || nextX < 0 ||
                nextY >= N || nextY < 0 ||
                nextH >= H || nextH < 0)
            {
                continue;
            }   

            if(box[nextH][nextY][nextX] == 0)
            {
                box[nextH][nextY][nextX] = 1;
                q.push({cost+1, {nextX,nextY,nextH}});
            }
        }
    }

    for(int h=0;h<H;h++)
    {
        for(int j=0;j<N;j++)
        {
            for(int i=0;i<M;i++)
            {
                if(box[h][j][i] == 0)
                {
                    maxCost = -1;
                }
            }
        }
    }
    return maxCost;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H);
    for(int h=0;h<H;h++)
    {
        box[h].resize(N);
        for(int j=0;j<N;j++)
        {
            box[h][j].resize(M);
            for(int i=0;i<M;i++)
            {
                cin >> box[h][j][i];
            }
        }
    }

    cout << GetMaxCost(box);
}