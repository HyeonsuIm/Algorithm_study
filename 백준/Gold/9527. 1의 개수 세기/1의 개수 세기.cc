#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void DecToBi(long long val, vector<int>& bi)
{
    while(val != 0)
    {
        bi.push_back(val % 2);
        val>>=1;
    }
}

long long CountNumber1(long long val, vector<int>& bi)
{
    int numCnt=bi.size();
    long long totalNumber1Cnt = 0;
    for(int i=bi.size()-1;i>=0;i--)
    {
        if(bi[i]==1)
        {
            val -= 1LL << i;
            totalNumber1Cnt += static_cast<long long>(i * static_cast<long long>(pow(2,i-1))) + static_cast<long long>(1) +val;
        }
    }
    return totalNumber1Cnt;
}

int main()
{
    long long start,end;
    cin >> start >>end;
    vector<int> startBi, endBi;
    
    DecToBi(start-1, startBi);
    DecToBi(end, endBi);

    long long totalCnt = CountNumber1(end, endBi);
    totalCnt -= CountNumber1(start-1, startBi);
    cout << totalCnt;
}