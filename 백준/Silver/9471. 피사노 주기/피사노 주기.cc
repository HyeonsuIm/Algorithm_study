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
    int P, N, M;
    cin >> P;
    vector<pair<int,int>> result;
    for(int i=0;i<P;i++)
    {
        cin >> N >> M;
       
        result.push_back({N, getCycleCnt(M)});
    }

    for(pair<int,int>& val : result)
    {
        cout << val.first << " " << val.second << endl;
    }
}