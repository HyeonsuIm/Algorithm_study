#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

bool isPassed[100][100];
bool hasKey[26];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int search(vector<string>& map, int h, int w)
{
    int result = 0;
    queue<pair<int,int>> q;
    vector<pair<int,int>> blockingList;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if( i == 0 || i == h-1 || j == 0 || j == w-1)
            {
                if(map[i][j] != '*')
                {
                    q.push(make_pair(i,j));
                    isPassed[i][j] = true;
                }
            }
        }
    }

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(map[y][x]=='$')
        {
            result += 1;
        }
        else if(map[y][x] >= 'a' && map[y][x] <= 'z')
        {
            hasKey[map[y][x]-'a']=true;
            auto iter = blockingList.begin();
            for(;iter != blockingList.end();)
            {
                int tempy=iter->first;
                int tempx=iter->second;
                if( map[tempy][tempx]-'A' == map[y][x]-'a' )
                {
                    q.push(make_pair(tempy,tempx));
                    iter =blockingList.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
        }
        else if(map[y][x] >= 'A' && map[y][x] <= 'Z')
        {
            if( !hasKey[map[y][x]-'A'] )
            {
                blockingList.push_back(make_pair(y,x));
                continue;
            }
        }

        for(int i=0;i<4;i++)
        {
            if(y+dy[i] >= 0 && y+dy[i] < h && x+dx[i] >= 0 && x+dx[i] < w)
            {
                if(map[y+dy[i]][x+dx[i]] != '*' &&
                    isPassed[y+dy[i]][x+dx[i]] == false)
                {
                    isPassed[y+dy[i]][x+dx[i]] = true;
                    q.push(make_pair(y+dy[i],x+dx[i]));
                }
            }
        }
    }
    return result;
}

int main()
{
    int T, h, w;
    cin >> T;

    for(int i=0;i<T;i++)
    {
        cin >> h >> w;
        vector<string> map(h);
        for(int i=0;i<h;i++)
        {
            string str;
            cin >> map[i];
        }

        string keyList;
        cin >> keyList;
        memset(hasKey, 0, sizeof(bool)*26);
        for(int i=0;i<100;i++)
        {
            memset(isPassed[i], 0, sizeof(bool)*100);
        }
        if(keyList[0] != '0')
        {
            for(int i=0;i<keyList.length();i++)
            {
                hasKey[keyList[i]-'a'] = true;
            }
        }
        cout << search(map, h, w) << endl;
    }
}