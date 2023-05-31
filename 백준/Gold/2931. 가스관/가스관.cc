#include <iostream>
#include <vector>
#include <string>

using namespace std;

int H, W;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


bool CheckDirection(int d, char type)
{
    if( d == 0 )
    {
        if( type == '|' ||
            type == '+' ||
            type == '2' ||
            type == '3')
        {
            return true;
        }
    }
    else if( d == 2)
    {
        if( type == '|' ||
            type == '+' ||
            type == '1' ||
            type == '4')
        {
            return true;
        }
    }
    else if( d == 1)
    {
        if( type == '-' ||
            type == '+' ||
            type == '3' ||
            type == '4')
        {
            return true;
        }
    }
    else if( d == 3)
    {
        if( type == '-' ||
            type == '+' ||
            type == '1' ||
            type == '2')
        {
            return true;
        }
    }
    return false;
}

int RotateDir(int d, char type)
{
    if( type == '1')
    {
        if(d==2) d=1;
        else d=0;
    }
    else if(type == '2')
    {
        if(d==0) d=1;
        else d=2;
    }
    else if(type == '3')
    {
        if(d==0) d=3;
        else d=2;
    }
    else if(type == '4')
    {
        if(d==1) d=0;
        else d=3;
    }
    return d;
}

int main(){
    cin >> H >> W;

    vector<string> map(H);
    for(int y=0;y<H;y++) { cin >> map[H-y-1]; };

    pair<int,int> start;
    for(int y=0;y<H;y++)
    {
        for(int x=0;x<W;x++)
        {
            if( map[y][x] == 'M' )
            {
                start.first = y;
                start.second = x;
            }
        }
    }

    int currDir = -1;
    do
    {
        if(currDir == -1)
        {
            for(int d=0;d<4;d++)
            {
                int nextY = start.first + dy[d];
                int nextX = start.second + dx[d];
                if(nextY>=0 && nextY<H && nextX >=0 && nextX < W )
                {
                    if( CheckDirection(d, map[nextY][nextX]) )
                    {
                        start = {nextY, nextX};
                        currDir = d;
                        break;
                    }
                }
            }
        }
        else
        {
            currDir = RotateDir(currDir, map[start.first][start.second]);
            start.first += dy[currDir];
            start.second += dx[currDir];
            if( !CheckDirection(currDir, map[start.first][start.second]))
            {
                break;
            }
        }
    }while(true);

    int fromDir = (currDir+2)%4;
    char missingBlock = 0;
    for(int d=0;d<4;d++)
    {
        if(fromDir == d) continue;
        int nextY = start.first + dy[d];
        int nextX = start.second + dx[d];
        if(nextY>=0 && nextY<H && nextX >=0 && nextX < W )
        {
            if( CheckDirection(d, map[nextY][nextX]) )
            {
                if(missingBlock != 0)
                {
                    missingBlock = '+';
                    break;
                }
                else
                {
                    if(abs(d-fromDir) == 2)
                    {
                        if(d % 2 == 0) missingBlock = '|';
                        else missingBlock = '-';
                    }
                    else
                    {
                        for(char type ='1' ; type<='4';type++)
                        {
                            if( d == RotateDir((fromDir+2)%4, type) )
                            {
                                missingBlock = type;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << H-start.first << " " << start.second+1 << " " << missingBlock;
}