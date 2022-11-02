#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> datas(N);
    vector<long long> sum(N+1, 0);
    for(int i=0;i<N;i++)
    {
        cin >> datas[i];
        sum[i+1] = datas[i] + sum[i];
    }

    int minLength = 100000;
    int startIdx = 0;
    for(int i=1;i<N+1;i++)
    {
        for(;startIdx<=i;startIdx++)
        {
            if(sum[i]-sum[startIdx] < S)
            {
                break;
            }
            else if(sum[i]-sum[startIdx] >= S)
            {
                minLength = min(minLength, i-startIdx);
                continue;
            }
        }
    }
    if(minLength == 100000)
    {
        cout << 0;
    }
    else
    {
        cout << minLength;
    }
}