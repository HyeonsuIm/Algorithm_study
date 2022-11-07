#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int parentIdx[100001];

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
    int N, M;
    cin >> N >> M;
	vector<tuple<int, int, int>> edgeList(M);
    for(int i=0;i<M;i++)
    {
		int A,B,C;
		cin >> A >> B >> C;
		edgeList[i]=make_tuple(C,A,B);
    }

	sort(edgeList.begin(), edgeList.end());

	long long maxWeight=0;
	int lastWeight=0;
	for(tuple<int,int,int>& edge : edgeList)
	{
		if(IsSameParent(get<1>(edge), get<2>(edge)) == false)
		{
			if(UnionSet(get<1>(edge), get<2>(edge)))
			{
				lastWeight = get<0>(edge);
				maxWeight += lastWeight;
			}
		}
	}
	cout << maxWeight - lastWeight << endl;
}