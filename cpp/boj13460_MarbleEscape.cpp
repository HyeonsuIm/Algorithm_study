#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int moveup(vector<string>& map, int& redX, int& redY, int otherX, int otherY)
{
    int i=0;
    int isSuccess = 0;
    for(i=redY;i>0;i--)
    {
        if(map[i-1][redX]=='#') break;
        else if(map[i-1][redX]=='O')
        {
            i--;
            isSuccess = 1;
            break;
        }
        if(otherX==redX&&otherY==i-1) break;
    }
    redY = i;
    return isSuccess;
}

int movedown(vector<string>& map, int& redX, int& redY, int otherX, int otherY)
{
    int i=0;
    int isSuccess = 0;
    for(i=redY;i<map.size()-1;i++)
    {
        if(map[i+1][redX]=='#') break;
        else if(map[i+1][redX]=='O')
        {
            i++;
            isSuccess=1;
            break;
        }
        if(otherX==redX&&otherY==i+1) break;
    }
    redY = i;
    return isSuccess;
}

int moveRight(vector<string>& map, int& redX, int& redY, int otherX, int otherY)
{
    int i=0;
    int isSuccess = 0;
    for(i=redX;i<map[0].size()-1;i++)
    {
        if(map[redY][i+1]=='#') break;
        else if(map[redY][i+1]=='O')
        {
            i++;
            isSuccess = 1;
            break;
        }
        if(otherX==i+1&&otherY==redY) break;
    }
    redX=i;
    return isSuccess;
}

int moveLeft(vector<string>& map, int& redX, int& redY, int otherX, int otherY)
{
    int i=0;
    int isSuccess = 0;
    for(i=redX;i>0;i--)
    {
        
        if(map[redY][i-1]=='#') break;
        else if(map[redY][i-1]=='O')
        {
            i--;
            isSuccess=1;
            break;
        }
        if(otherX==i-1&&otherY==redY) break;
    }
    redX=i;
    return isSuccess;
}

int moveNext(vector<string>& map, int redX, int redY, int blueX, int blueY, int type, pair<pair<int,int>,pair<int,int>>& result)
{
    int tempRedX = redX;
    int tempRedY = redY;
    int tempBlueX = blueX;
    int tempBlueY = blueY;
    int resultRed=0;
    int resultBlue=0;
    if(type==1)
    {
        if(redY < blueY)
        {
            resultRed = moveup(map, redX, redY, 0,0);
            resultBlue = moveup(map,blueX,blueY, redX, redY);
            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
        else
        {
            resultBlue = moveup(map, blueX, blueY, 0,0);
            resultRed = moveup(map,redX,redY, blueX, blueY);
            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
    }
    else if(type==2)
    {
        if(redY > blueY)
        {
            resultRed = movedown(map, redX, redY,0,0);
            resultBlue= movedown(map,blueX,blueY,redX,redY);
            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
        else
        {
            resultBlue = movedown(map, blueX, blueY,0,0);
            resultRed =movedown(map,redX,redY,blueX,blueY);
            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
    }
    else if(type==3)
    {
        if(redX < blueX)
        {
            resultRed = moveLeft(map, redX, redY,0,0);
            resultBlue = moveLeft(map,blueX,blueY,redX,redY);
            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
        else
        {
            resultBlue = moveLeft(map, blueX, blueY,0,0);
            resultRed = moveLeft(map,redX,redY,blueX,blueY);

            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
    }

       else if(type==4)
    {
        if(redX > blueX)
        {
            resultRed = moveRight(map, redX, redY,0,0);
            resultBlue = moveRight(map,blueX,blueY,redX,redY);

            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
        else
        {
            resultBlue = moveRight(map, blueX, blueY,0,0);
            resultRed = moveRight(map,redX,redY,blueX,blueY);
            if(resultBlue == 1)
            {
                return 2;
            }
            if(resultRed == 1)
            {
                return 1;
            }
        }
    }

    if( tempRedX != redX || tempRedY != redY||tempBlueX!=blueX||tempBlueY!=blueY)
    {
        result.first.first=redX;
        result.first.second=redY;
        result.second.first=blueX;
        result.second.second=blueY;
        return 0;
    }
    else
    {
        return 2;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> map(N);
    for(int i=0;i<N;i++)
    {
        cin >> map[i];
    }

    int redX, redY;
    int blueX, blueY;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[i][j]=='R')
            {
                redX = j;
                redY = i;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B')
            {
                blueX=j;
                blueY=i;
                map[i][j] = '.';
            }
        }
    }

    queue<tuple<int, pair<int,int>,pair<int,int>>> q;
    q.push(make_tuple(0,make_pair(redX,redY), make_pair(blueX,blueY)));
    int bestCost = 0;
    pair<pair<int,int>,pair<int,int>> nextVisit;
    while(!q.empty())
    {
        tuple<int, pair<int,int>,pair<int,int>>& data = q.front();
        redX = get<1>(data).first;
        redY = get<1>(data).second;

        blueX = get<2>(data).first;
        blueY = get<2>(data).second;

        int cost = get<0>(data);
        if(cost>=10)
        {
            break;
        }
        q.pop();
        int result = 0;
        for(int i=1;i<=4;i++)
        {
            result = moveNext(map, redX,redY,blueX,blueY,i,nextVisit);
            if(result == 1)
            {
                bestCost = cost+1;
                break;
            }
            else if(result == 2)
            {
                continue;
            }
            q.push(make_tuple(cost+1, make_pair(nextVisit.first.first, nextVisit.first.second), make_pair(nextVisit.second.first, nextVisit.second.second)));
        }
        if(bestCost != 0)
        {
            break;
        }
    }
    if( bestCost == 0)
    {
        cout << -1;
    }
    else
    {
        cout << bestCost;
    }
}