#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    stack<pair<int,int>> s;
    scanf("%d", &N);
    long long cnt=0;
    for(int i=0;i<N;i++)
    {
        int tall;
        scanf("%d", &tall);
        while(true)
        {
            if(s.empty())
            {
                s.push({tall,1});
                break;
            }
            else if( s.top().first < tall )
            {
                cnt += s.top().second;
                s.pop();
            }
            else if(s.top().first == tall)
            {
                cnt += s.top().second;
                if(s.size()>1) cnt+=1;
                s.top().second++;
                break;
            }
            else
            {
                s.push({tall,1});
                cnt+=1;
                break;
            }
        }
    }
    printf("%lld", cnt);
}