#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

using namespace std;
int parentIdx[10001];

int GetParent(int node)
{
	if(parentIdx[node] == 0) return node;
	else return parentIdx[node] = GetParent(parentIdx[node]);
}


bool IsSameParent(int node1, int node2)
{
	int parent1 = GetParent(node1);
	int parent2 = GetParent(node2);

	if( parent1 == parent2 && parent1 != 0) return true;
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
    int N;
    cin >> N;
    vector<pair<float,float>> pointList(N);
    for(int i=0;i<N;i++)
    {
        float x,y;
        cin >> x >> y;
        pointList[i] = make_pair(x,y);
    }

    vector<tuple<float, int, int>> edgeList;
    edgeList.reserve(N*N);
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            edgeList.push_back(make_tuple(sqrt(pow(pointList[i].first-pointList[j].first,2)+pow(pointList[i].second-pointList[j].second,2)),i,j));
        }
    }
    
	sort(edgeList.begin(), edgeList.end());

	float maxWeight=0;
	for(tuple<float,int,int>& edge : edgeList)
	{
		if(IsSameParent(get<1>(edge), get<2>(edge)) == false)
		{
			if(UnionSet(get<1>(edge), get<2>(edge)))
			{
				maxWeight += get<0>(edge);
			}
		}
	}
    cout.setf(ios::fixed);
    cout.precision(2);
	cout << maxWeight << endl;
}