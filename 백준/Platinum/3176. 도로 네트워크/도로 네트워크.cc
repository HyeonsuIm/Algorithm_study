#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_TREE_DEPTH 17

int depth[100001];
int parentNodeIdx[100001][MAX_TREE_DEPTH+1];
int parentMin[100001][MAX_TREE_DEPTH+1];
int parentMax[100001][MAX_TREE_DEPTH+1];

void MakeTree(vector<vector<pair<int,int>>>& graph, int curr)
{
    // depth[1] = 1;
    // queue<int> q;
    // q.push(1);
    // while(!q.empty())
    // {
    //     int curr = q.front();
    //     q.pop();
    //     for(auto next : graph[curr])
    //     {
    //         int nextIdx = next.first;
    //         if(depth[nextIdx] == 0)
    //         {
    //             depth[nextIdx] = depth[curr]+1;
    //             parentNodeIdx[nextIdx][0] = curr;
    //             parentMin[nextIdx][0] = next.second;
    //             parentMax[nextIdx][0] = next.second;
    //             q.push(nextIdx);
    //         }
    //     }
    // }
    for(auto child: graph[curr]){		
		int next = child.first;		
		int BaseV = child.second;
		//  이미 돌아본 도시는 패스 
		if(depth[next]!=0) continue;

		depth[next] = depth[curr]+1;
		// 2^0 번째 부모 저장 
		parentNodeIdx[next][0] = curr;
		// 바로 부모까지 작은길이 = 큰길이 
		parentMin[next][0] = BaseV;
        parentMax[next][0] = BaseV;
		MakeTree(graph,next); 
	}
}

void MakeParents(int N)
{
    for(int k=0;k<MAX_TREE_DEPTH;k++)
    {
        for(int i=2;i<=N;i++)
        {
            int parent = parentNodeIdx[i][k];
            if( parent != 0)
            {
                parentNodeIdx[i][k+1] = parentNodeIdx[parent][k];
                parentMin[i][k+1] = min(parentMin[i][k], parentMin[parent][k]);
                parentMax[i][k+1] = max(parentMax[i][k], parentMax[parent][k]);
            }
        }
    }
}

void search(int from, int to)
{
    int minLen=0x7fffffff, maxLen = 0;
    if(depth[from] < depth[to]) swap(from, to);
    int depthDiff = depth[from]-depth[to];
    int cnt=0;
    while(depthDiff)
    {
        if(depthDiff%2==1)
        {
            minLen = min(minLen, parentMin[from][cnt]);
            maxLen = max(maxLen, parentMax[from][cnt]);
            from = parentNodeIdx[from][cnt];
        }
        depthDiff /= 2;
        cnt++;
    }

    if(from!=to)
    {
        for(int i=MAX_TREE_DEPTH;i>=0;i--)
        {
            if(parentNodeIdx[from][i] != parentNodeIdx[to][i])
            {
                minLen = min(minLen, parentMin[from][i]);
                maxLen = max(maxLen, parentMax[from][i]);
                minLen = min(minLen, parentMin[to][i]);
                maxLen = max(maxLen, parentMax[to][i]);

                from = parentNodeIdx[from][i];
                to = parentNodeIdx[to][i];
            }
        }
        minLen = min(minLen, parentMin[from][0]);
        maxLen = max(maxLen, parentMax[from][0]);
        minLen = min(minLen, parentMin[to][0]);
        maxLen = max(maxLen, parentMax[to][0]);
        from = parentNodeIdx[from][0];
    }

    printf("%d %d\n", minLen, maxLen);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N, K;
    scanf("%d", &N);
    vector<vector<pair<int,int>>> graph(N+1);
    for(int i=0;i<N-1;i++)
    {
        int from, to, length;
        scanf("%d %d %d", &from, &to, &length);
        graph[from].push_back({to,length});
        graph[to].push_back({from,length});
    }

    depth[1] = 1;
    MakeTree(graph, 1);
    MakeParents(N);

    scanf("%d", &K);
    for(int i=0;i<K;i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        search(from, to);
    }
    return 0;
}