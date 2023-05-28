#include <iostream>
#include <vector>
using namespace std;

int dp[2001][2001];

int main()
{
    int N, M;
    scanf("%d", &N);

    vector<int> vals(N+1);
    for(int i=1;i<=N;i++) cin >> vals[i];
    for(int i=1;i<=N;i++) dp[i][i] = 1;
    for(int i=1;i<=N-1;i++) 
    {
        if(vals[i+1]==vals[i]) dp[i][i+1] = 1;
    }
    
    for(int cnt=3;cnt<=N;cnt++)
    {
        for(int S=1;S<=N;S++)
        {
            int E = S+cnt-1;
            if(E > N) break;;
            if(dp[S+1][E-1])
            {
                if(vals[S] == vals[E]) dp[S][E] = 1;
            }
        }
    }

    int S, E;
    scanf("%d", &M);
    for(int i=0;i<M;i++)
    {
        scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }
}