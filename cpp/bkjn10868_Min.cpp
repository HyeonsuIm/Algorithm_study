#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INVALID_MIN 0x7fffffff

int arr[100000];

void InsertSegmentTree(vector<int>& tree, int node, int start, int end)
{
    if( start==end ) 
    {
        tree[node] = arr[start];
    }
    else
    {        
        int mid = (start+end)/2;
        InsertSegmentTree(tree, node*2, start, mid);
        InsertSegmentTree(tree, node*2+1, mid+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int GetMin(vector<int>& tree, int node, int from, int to, int start, int end)
{
    if( to < start || from > end) return INVALID_MIN;
    if( from <= start && end <= to ) return tree[node];
    
    int mid = (start+end)/2;
    int minVal = GetMin(tree, node*2, from, to, start, mid);
    minVal = min(minVal, GetMin(tree, node*2+1, from, to, mid+1, end));

    return minVal;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int maxTreeCnt = 1 << (static_cast<int>(ceil(log2(N)))+1);
    vector<int> tree(maxTreeCnt);

    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    InsertSegmentTree(tree, 1, 0, N-1);

    int minVal;
    int a,b;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d", &a, &b);
        minVal = GetMin(tree, 1, a-1, b-1, 0, N-1);
        printf("%d\n", minVal);
    }
}