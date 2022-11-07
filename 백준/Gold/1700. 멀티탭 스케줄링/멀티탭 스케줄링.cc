#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INVALID_DEVICES_INDEX 101

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    vector<int> devices(K);
    for(int i=0;i<K;i++)
    {
        cin >> devices[i];
    }

    int removeCnt = 0;
    vector<int> plugs;
    for(int i=0;i<K;i++)
    {
        auto plugIter = find(plugs.begin(), plugs.end(), devices[i]);
        if(plugIter != plugs.end())
        {
            continue;
        }

        if( plugs.size() != N)
        {
            plugs.push_back(devices[i]);
            continue;
        }

        int plugIdx = -1;
        int maxIdx = 0;
        for(int j=0;j<N;j++)
        {
            auto iter = find(devices.begin()+i, devices.end(), plugs[j]);
            if( iter != devices.end())
            {
                int dist = distance(devices.begin(), iter);
                if( maxIdx < dist)
                {
                    maxIdx = dist;
                    plugIdx = j;
                }
            }
            else
            {
                maxIdx = INVALID_DEVICES_INDEX;
                plugIdx = j;
                break;
            }
        }

        plugs.erase(plugs.begin()+plugIdx);
        removeCnt+=1;
        plugs.push_back(devices[i]);
    }

    cout << removeCnt;
}