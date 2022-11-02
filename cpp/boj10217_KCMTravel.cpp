#include <iostream>
#include <vector>
#include <tuple>
#include <memory.h>
#include <queue>

using namespace std;

unsigned int dp[101][10001];
int N, M, K;

#define INF 0xffffffff


void SearchGraph(vector<vector<tuple<int,int,int>>>& travelList, int node)
{
    priority_queue<tuple<unsigned int,int,int>, vector<tuple<unsigned int,int,int>>, greater<tuple<unsigned int,int,int>>> pq;
    pq.push({0,0,node});
	dp[0][0] = 0;
    while(!pq.empty())
    {
        tuple<unsigned int,int,int> data = pq.top(); pq.pop();
        int current = get<2>(data);
        int currentCost = get<1>(data);
        unsigned int currentTravel = get<0>(data);

        for(tuple<int,int,int>& nextNode :travelList[current])
        {
            int next = get<0>(nextNode);
            int nextCost = get<1>(nextNode)+currentCost;
            unsigned int nextTravel = get<2>(nextNode)+dp[current][currentCost];

            if(nextCost > M) continue;
            if(dp[next][nextCost] <= nextTravel) continue;

			dp[next][nextCost] = nextTravel;
			pq.push({nextTravel, nextCost, next});
        }
    }
}

int Solve(vector<vector<tuple<int,int,int>>>& travelList)
{
    memset(dp, INF, sizeof(dp));
    SearchGraph(travelList, 0);

	unsigned int minimum = INF;
	for(int i=0;i<=M;i++)
	{
		minimum = min(minimum, dp[N-1][i]);
	}

	return minimum;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> N >> M >> K;
        vector<vector<tuple<int,int,int>>> travelList(N);
        for(int j=0;j<K;j++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            travelList[u-1].push_back({v-1,c,d});
        }

        int result = Solve(travelList);
        if( result == INF)
        {
            cout << "Poor KCM" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }
}