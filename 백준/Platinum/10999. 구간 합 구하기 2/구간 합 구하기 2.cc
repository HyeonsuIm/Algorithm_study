#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> arr;

long long MakeTree(vector<long long>& tree, int node, int start, int end)
{
    if(start==end)
    {
        return tree[node] = arr[start];
    }
    else
	{
		int mid = (start+end)/2;
		tree[node] += MakeTree(tree, node*2, start, mid);
		tree[node] += MakeTree(tree, node*2+1, mid+1, end);
		return tree[node];
	}
}

void UpdateTreeLazy(vector<long long>& tree, vector<long long>& lazyTree, int node, int start, int end)
{
	if( lazyTree[node] != 0)
	{
		tree[node] += lazyTree[node]*static_cast<long long>(end-start+1);
		if( start != end)
		{
			lazyTree[node*2] += lazyTree[node];
			lazyTree[node*2+1] += lazyTree[node];
		}
		lazyTree[node] = 0;
	}
}

void UpdateTree(vector<long long>& tree, vector<long long>& lazyTree, int node, long long val, int from, int to, int start, int end)
{
	UpdateTreeLazy(tree, lazyTree, node, start, end);
	if( from > end || to < start) return;
	if( from <= start && to >= end)
	{
		tree[node] += val*static_cast<long long>(end-start+1);
		if(start != end)
		{
			lazyTree[node*2] += val;
			lazyTree[node*2+1] += val;
		}
	}
	else
	{
		int mid = (start+end)/2;
		UpdateTree(tree, lazyTree, node*2, val, from, to, start, mid);
		UpdateTree(tree, lazyTree, node*2+1, val, from, to, mid+1, end);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
}

long long GetSubSum(vector<long long>& tree, vector<long long>& lazyTree, int node, int from, int to, int start, int end)
{
	UpdateTreeLazy(tree, lazyTree, node, start, end);
	if( from > end || to < start) return 0;
	if( from <= start && to >= end)
	{
		return tree[node];
	}

	long long result = 0;
	int mid = (start+end)/2;
	result += GetSubSum(tree, lazyTree, node*2, from, to, start, mid);
	result += GetSubSum(tree, lazyTree, node*2+1, from, to, mid+1, end);
	return result;
}


int main()
{
    int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

    int height = static_cast<int>(ceil(log2(N)))+1;
    vector<long long> tree(1 << height);
	vector<long long> lazyTree(1 << height);

    arr.resize(N);
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    MakeTree(tree, 1, 0, N-1);

	int a, b, c;
	long long d;
    for(int i=0;i<M+K;i++)
    {
		scanf("%d %d %d", &a, &b, &c);
        if( a == 1)
        {
			scanf("%lld", &d);
			UpdateTree(tree, lazyTree, 1, d, b-1, c-1, 0, N-1);
        }
        else
        {
			printf("%lld\n",GetSubSum(tree, lazyTree, 1, b-1, c-1, 0, N-1));
        }
    }
}