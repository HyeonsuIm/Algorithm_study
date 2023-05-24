#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int getCycleCnt(int modVal)
{
    long long lastVal = pow(modVal,2);
    int resultVal = 0;
    int val[3] = {0, 1, 1};
    for(long long j=3;j<lastVal+2;j++)
    {
        swap(val[0], val[1]);
        swap(val[2], val[1]);
        val[2] = (val[0]+val[1])% modVal;
        if(val[1] == 0 && val[2] == 1)
        {
            resultVal = j-1;
            break;
        }
    }
    return resultVal;
}

int main()
{
    const int modVal = 1000000;
    long long n;
    cin >> n;

    int cnt = getCycleCnt(modVal);
    vector<int> fibo(cnt);
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<cnt;i++)
    {
        fibo[i] = (fibo[i-1]+fibo[i-2])%modVal;
    }
    cout << fibo[n%cnt];
}