#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define SET_BIT(bit, position) (bit |= (1<<position))
#define CLR_BIT(bit, position) (bit &= ~(1<<position))

map<long long, map<int,int>> memorized;

int Search(vector<bool>& tickets, vector<int>& chairs, int depth, int status)
{
    auto iter = memorized.find(status);
    if( iter != memorized.end())
    {
        auto depthIter = iter->second.find(depth);
        if(depthIter != iter->second.end())
        {
            return memorized[status][depth];
        }
    }

    if( depth == tickets.size())
    {
        return 1;
    }
    int cnt=0;
    if(chairs[depth]!=-1)
    {
        cnt += Search(tickets, chairs, depth+1, status);
    }
    else
    {
        for(int i=depth-1;i<=depth+1;i++)
        {
            if(i < 0 || i >= tickets.size()) continue;
            if(!tickets[i])
            {
                tickets[i] = true;
                chairs[depth] = i;
                SET_BIT(status, i);
                cnt += Search(tickets, chairs, depth+1, status);
                CLR_BIT(status, i);
                chairs[depth] = -1;
                tickets[i]=false;
            }
        }
    }
    memorized[status][depth] = cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> tickets(n, false);
    vector<int> chairs(n, -1);
    int status = 0;
    for(int i=0;i<m;i++)
    {
        int position;
        cin >> position;
        tickets[position-1] = true;
        chairs[position-1] = position-1;
        SET_BIT(status, position-1);
    }

    
    cout << Search(tickets, chairs, 0, status);
}