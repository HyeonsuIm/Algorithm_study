#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;

    vector<pair<int,int>> jewelList(N);
    for(int i=0;i<N;i++)
    {
        cin >> jewelList[i].first >> jewelList[i].second;
    }


    sort(jewelList.begin(), jewelList.end());

    vector<int> begSizes(K);
    for(int i=0;i<K;i++)
    {
        cin >> begSizes[i];
    }
    sort(begSizes.begin(), begSizes.end());
    long long costs = 0;
    int j=0;
    int jEnd = jewelList.size();
    priority_queue<int, vector<int>> pq;
    for(int i=0;i<begSizes.size();i++)
    {
        while(begSizes[i] >= jewelList[j].first && j != jEnd)
        {
            pq.push(jewelList[j].second);
            j+=1;
        }
        if(!pq.empty())
        {
            costs += pq.top();
            pq.pop();
        }
    }
    cout << costs;
}