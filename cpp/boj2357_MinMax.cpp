#include <iostream>
#include <cmath>
using namespace std;

#define INVALID_MIN 0x7fffffff
#define INVALID_MAX 0

int arr[100000];

void InsertSegmentTree(pair<int,int> *tree, int node, int start, int end)
{
    if( start==end ) 
    {
        tree[node].first = tree[node].second = arr[start];
    }
    else
    {        
        int mid = (start+end)/2;
        InsertSegmentTree(tree, node*2, start, mid);
        InsertSegmentTree(tree, node*2+1, mid+1, end);
        tree[node].first = min(tree[node*2].first, tree[node*2+1].first);
        tree[node].second = max(tree[node*2].second, tree[node*2+1].second);
    }
}

pair<int,int> GetMinMax(pair<int,int>* tree, int node, int from, int to, int start, int end)
{
    if( to < start || from > end) return {INVALID_MIN, INVALID_MAX};
    if( from <= start && end <= to ) return tree[node];
    
    int mid = (start+end)/2;
    pair<int,int> minMax = GetMinMax(tree, node*2, from, to, start, mid);
    pair<int,int> minMax2 = GetMinMax(tree, node*2+1, from, to, mid+1, end);

    return {min(minMax.first, minMax2.first), max(minMax.second, minMax2.second)};
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int maxTreeCnt = 1 << (static_cast<int>(ceil(log2(N)))+1);
    pair<int,int> *tree = new pair<int,int>[maxTreeCnt];

    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    InsertSegmentTree(tree, 1, 0, N-1);

    pair<int,int> minMax;
    int a,b;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d", &a, &b);
        minMax = GetMinMax(tree, 1, a-1, b-1, 0, N-1);
        printf("%d %d\n", minMax.first, minMax.second);
    }
    delete[] tree;
}