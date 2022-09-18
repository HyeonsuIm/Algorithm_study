#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

using namespace std;
int parentIdx[100000];

int GetParent(int node)
{
	if(parentIdx[node] == node) return node;
	else return parentIdx[node] = GetParent(parentIdx[node]);
}


bool IsSameParent(int node1, int node2)
{
	int parent1 = GetParent(node1);
	int parent2 = GetParent(node2);

	if( parent1 == parent2) return true;
	else return false;
}

bool UnionSet(int node1, int node2)
{
	int parent1 = GetParent(node1);
	int parent2 = GetParent(node2);

	parentIdx[parent1] = parent2;
	return true;
}

int main()
{
    for(int i=0;i<100000;i++)
    {
        parentIdx[i]=i;
    }
    int N;
    cin >> N;
    vector<pair<int,int>> distList[3];
    distList[0].resize(N);
    distList[1].resize(N);
    distList[2].resize(N);
    for(int i=0;i<N;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        distList[0][i] = make_pair(x, i);
        distList[1][i] = make_pair(y, i);
        distList[2][i] = make_pair(z, i);
    }

    vector<tuple<int, int, int>> edgeList;
    edgeList.reserve(N*3);
    for(int k=0;k<3;k++)
    {
        sort(distList[k].begin(), distList[k].end());
        for(int i=0;i<N-1;i++)
        {
            edgeList.push_back(make_tuple(
                distList[k][i+1].first-distList[k][i].first,
                distList[k][i].second,
                distList[k][i+1].second));
        }
    }
	sort(edgeList.begin(), edgeList.end());

	int maxWeight=0;
	for(tuple<int,int,int>& edge : edgeList)
	{
		if(IsSameParent(get<1>(edge), get<2>(edge)) == false)
		{
			if(UnionSet(get<1>(edge), get<2>(edge)))
			{
				maxWeight += get<0>(edge);
			}
		}
	}
	cout << maxWeight << endl;
}