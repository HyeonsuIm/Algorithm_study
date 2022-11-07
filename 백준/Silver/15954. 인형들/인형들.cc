#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, K;


double GetCosts(vector<int>& preferPersons, int idx, int cnt, long long sum)
{
    double val=0;
    double average = static_cast<double>(sum) / static_cast<double>(cnt);
    for(int i=0;i<cnt;i++)
    {
        val += pow(static_cast<double>(preferPersons[idx+i]) - average,2);
    }
    return sqrt(val/static_cast<double>(cnt));
}

double GetBestCase(vector<int>& preferPersons)
{
    double bestCost = numeric_limits<double>::max();
    for(int idx=0;idx<N;idx++)
    {
        long long sum=0;
        int i;
        int cnt = 0;
        for(i=idx;i<N;i++)
        {
            sum+=static_cast<long long>(preferPersons[i]);
            cnt++;
            if(cnt >= K)
            {
                bestCost=min(GetCosts(preferPersons, idx, cnt, sum),bestCost);
            }
        }
    }
    
    return bestCost;
}

int main()
{
    cin >> N >> K;
    vector<int> preferPersons(N);
    for(int i=0;i<N;i++)
    {
        cin >> preferPersons[i];
    }
    cout.precision(11);
    cout << GetBestCase(preferPersons) << endl;
}