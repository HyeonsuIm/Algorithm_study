#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> tree;

void ChangeSegmentTree(int index, long long val, int node, int start, int end)
{
    if( start == end )
    {
        tree[node] = val;
    }
    else
    {
        int mid = (start+end)/2;
        if( index <= mid)
        {
            ChangeSegmentTree(index, val, node*2, start, mid);
        }
        else
        {
            ChangeSegmentTree(index, val, node*2+1, mid+1, end);
        }
        tree[node] = (tree[node*2] * tree[node*2+1])%1000000007;
    }
}

long long GetMulti(int from, int to, int node, int start, int end)
{
    if( from > end || to < start) return 1;
    if( from <= start && to >= end) return tree[node];

    int mid = (start+end)/2;
    long long result = GetMulti(from, to, node*2, start, mid);
    result = (result * GetMulti(from, to, node*2+1, mid+1, end))%1000000007;

    return result;
}

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int height = static_cast<int>(ceil(log2(N)))+1;
    tree.resize(1 << height, 1);
    for(int i=0;i<N;i++)
    {
        int val;
        scanf("%d", &val);
        ChangeSegmentTree(i, val, 1, 0, N-1);
    }

    for(int i=0;i<M+K;i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if( a == 1)
        {
            ChangeSegmentTree(b-1, c, 1, 0, N-1);
        }
        else
        {
            printf("%lld\n", GetMulti(b-1, c-1, 1, 0, N-1));
        }
    }
}