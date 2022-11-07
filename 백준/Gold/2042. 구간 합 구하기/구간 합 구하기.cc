#include <iostream>

using namespace std;

long long tree[2097153];

long long ChangeSegmentTree(int index, long long val, int node, int start, int end)
{
    long long diff;
    if( start == end )
    {
        diff = val - tree[node];
        tree[node] = val;
        return diff;
    }

    int mid = (start+end)/2;
    if( index <= mid)
    {
        diff = ChangeSegmentTree(index, val, node*2, start, mid);
    }
    else
    {
        diff = ChangeSegmentTree(index, val, node*2+1, mid+1, end);
    }
    tree[node] += diff;
    return diff;
}

long long GetSum(int from, int to, int node, int start, int end)
{
    if( from > end || to < start) return 0;
    if( from <= start && to >= end) return tree[node];
    long long result = 0;

    int mid = (start+end)/2;
    result += GetSum(from, to, node*2, start, mid);
    result += GetSum(from, to, node*2+1, mid+1, end);

    return result;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        long long val;
        cin >> val;
        ChangeSegmentTree(i, val, 1, 0, 1048576);
    }

    for(int i=0;i<M+K;i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if( a == 1)
        {
            ChangeSegmentTree(b-1, c, 1, 0, 1048576);
        }
        else
        {
            cout << GetSum(b-1, c-1, 1, 0, 1048576) << endl;
        }
    }
}