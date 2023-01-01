#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    A -=1;
    B-=1;
    vector<vector<pair<int,int>>> edges(N);
    int maxCost = 0;
    int minCost = 0x7fffffff;
    for(int i=0;i<M;i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        edges[from-1].push_back(make_pair(to-1, cost));
        edges[to-1].push_back(make_pair(from-1, cost));

        maxCost = max(maxCost, cost);
        minCost = min(minCost, cost);
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
    // vector<int> precalculatedCost(N, -1);
    // pq.push({0,B});
    // while(!pq.empty())
    // {
    //     int cost = pq.top().first;
    //     int position = pq.top().second;
    //     pq.pop();

    //     if( precalculatedCost[position] != -1)
    //     {
    //         continue;
    //     }
    //     precalculatedCost[position] = cost;
    //     for(pair<int,int>& next : edges[position])
    //     {
    //         if(precalculatedCost[next.first] == -1 )
    //         {
    //             pq.push({cost + next.second, next.first});
    //         }
    //     }
    // }

    int from = minCost;
    int to = maxCost;
    int bestCost = 0;
    do
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int currC = (from+to)/2;
        bool success = false;
        vector<bool> visited(N, false);
        pq.push({0,A});
        while(!pq.empty())
        {
            int currCost = pq.top().first;
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
            for(pair<int,int>& next : edges[position])
            {
                if(next.second > currC)
                {
                    continue;
                }

                //int cost = precalculatedCost[next.first] + currCost + next.second;
                int cost = currCost + next.second;
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