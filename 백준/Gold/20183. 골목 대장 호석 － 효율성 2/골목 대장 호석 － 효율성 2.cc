#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, A, B;
    long long C;
    cin >> N >> M >> A >> B >> C;
    A -=1;
    B-=1;
    vector<vector<pair<int,long long>>> edges(N);
    long long maxCost = 0;
    long long minCost = 1000000000;
    for(int i=0;i<M;i++)
    {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;

        edges[from-1].push_back(make_pair(to-1, cost));
        edges[to-1].push_back(make_pair(from-1, cost));

        maxCost = max(maxCost, cost);
        minCost = min(minCost, cost);
    }
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq1;
    vector<long long> precalculatedCost(N, -1);
    pq1.push({0,B});
    while(!pq1.empty())
    {
        long long cost = pq1.top().first;
        int position = pq1.top().second;
        pq1.pop();

        if( precalculatedCost[position] != -1)
        {
            continue;
        }
        precalculatedCost[position] = cost;
        for(pair<int, long long>& next : edges[position])
        {
            if(precalculatedCost[next.first] == -1 )
            {
                pq1.push({cost + next.second, next.first});
            }
        }
    }

    int from = minCost;
    int to = maxCost;
    int bestCost = 0;
    do
    {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        int currC = (from+to)/2;
        bool success = false;
        vector<bool> visited(N, false);
        pq.push({0,A});
        while(!pq.empty())
        {
            long long currCost = pq.top().first;
            int position = pq.top().second;
            pq.pop();

            if(visited[position])
            {
                continue;
            }
            if(position==B)
            {
                success=true;
                break;
            }
            visited[position] = true;
            for(pair<int,long long>& next : edges[position])
            {
                if( next.second > currC ||
                    precalculatedCost[next.first] == -1)
                {
                    continue;
                }

                long long cost = precalculatedCost[next.first] + currCost + next.second;
                //int cost = currCost + next.second;
                if( visited[next.first] == false &&
                    cost <= C )
                {
                    pq.push({currCost + next.second,next.first});
                }
            }    
        }
        if(success == false)
        {
            from = currC+1;
        }
        else
        {
            to = currC-1;
            bestCost = currC;
        }
        //cout << from << " " << to << endl;
    }while(from <= to);

    if(bestCost == 0)
    {
        cout << -1;
    }
    else
    {
        cout << bestCost;
    }
    return 0;
}