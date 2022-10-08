#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define INVALID_COST 0x7fffffff

vector<unordered_map<unsigned int, int>> map;
vector<vector<pair<int,int>>> links;
unsigned int FINISH_BIT_MASK;

int searchMap(unsigned int bitMask, int node)
{
    if(bitMask == FINISH_BIT_MASK)
    {
        for(pair<int,int>& nextNode :links[node])
        {
            if(nextNode.first == 0)
            {
                return nextNode.second;
            }
        }
        return INVALID_COST;
    }
    else
    {
        if(map[node].find(bitMask) != map[node].end())
        {
            return map[node][bitMask];
        }
        else
        {
            int minCost = INVALID_COST;
            for(pair<int,int>& nextNode :links[node])
            {
                if( 0 == (bitMask & (1 << nextNode.first)) )
                {
                    unsigned int bitMaskNext = bitMask | (1 << nextNode.first);
                    int cost = searchMap(bitMaskNext, nextNode.first);
                    if( cost != INVALID_COST)
                    {
                        minCost = min(minCost, cost+nextNode.second);
                    }
                }
            }
            map[node][bitMask] = minCost;
            return minCost;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    FINISH_BIT_MASK = (1 << N) - 1;
    links.resize(N);
    map.resize(N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int cost;
            cin >> cost;
            if( cost != 0 )
            {
                links[i].push_back(make_pair(j, cost));
            }
        }
    }

    cout << searchMap(1,0) << endl;
}