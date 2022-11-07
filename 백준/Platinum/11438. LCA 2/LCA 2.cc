#include <iostream>
#include <vector>

using namespace std;

#define MAX_BITS 18

int parents[100001][MAX_BITS];
int depths[100001];
bool used[100001];

vector<int> graph[100001];
int N, M;
int MAX_HEIGHT;

void MakeParents(int parent, int node, int depth)
{
    if(used[node]) return;

    used[node]=true;
    parents[node][0] = parent;
    depths[node] = depth;
    for(int nextNode : graph[node])
    {
        MakeParents(node, nextNode, depth+1);
    }
}

int GetCommonParent(int node1, int node2)
{
    if(depths[node1] < depths[node2])
    {
        swap(node1,node2);
    }

    int diff = depths[node1]-depths[node2];
    if( diff != 0)
    {
        for(int i=0;diff >0;i++,diff>>=1)
        {
            if(diff%2 == 1)
            {
                node1 = parents[node1][i];
            }
        }
    }

    if(node1==node2) return node1;

    for(int i=MAX_HEIGHT;i>=0;i--)
    {
        if(parents[node1][i] != parents[node2][i])
        {
            node1 = parents[node1][i];
            node2 = parents[node2][i];
        }
    }
    return parents[node1][0];
}

int main()
{
    scanf("%d", &N);
    for(int i=0;i<N-1;i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    MakeParents(0, 1, 1);
    int temp = N;
    while(temp >1){
        temp = temp>>1;
        ++MAX_HEIGHT;
    }

    for(int i=1;i<=MAX_HEIGHT;i++)
    {
        for(int j=2;j<=N;j++)
        {
            parents[j][i] = parents[parents[j][i-1]][i-1];
        }
    }

    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        int node1, node2;
        scanf("%d %d",&node1, &node2);
        printf("%d\n",GetCommonParent(node1, node2));
    }
}