#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int dfs(vector<int>& arr, int N, int K, int depth, int eatPoint, int point)
{
    if( eatPoint >= K )
    {
        point += eatPoint-K;
    }

    if(depth == arr.size())
    {
        return point;
    }

    if(eatPoint < K && eatPoint != -1)
    {
        return dfs(arr,N,K,depth+1,eatPoint+arr[depth], point);
    }
    else
    {
        return max(dfs(arr,N,K,depth+1,-1,point), dfs(arr,N,K,depth+1, arr[depth], point));
    }
}

int main()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    vector<int> arr(N);
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    int result = dfs(arr, N, K, 0, -1, 0);
    cout << result;
    return 0;
}