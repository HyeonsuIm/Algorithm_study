#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void MakeSumInfo(const vector<int>& array, vector<int>& sumInfo, int index,unordered_map<int,int>& result)
{
    if (array.size() == index)
    {
        return;
    }

    sumInfo[index+1]=sumInfo[index]+array[index];
    for(int i=0;i<=index;i++)
    {
        result[sumInfo[index+1]-sumInfo[i]]+=1;
    }
    MakeSumInfo(array, sumInfo, index+1, result);
}

int main()
{
    int T, N, M;
    cin >> T >> N;
    vector<int> array[2], sumInfo[2];
    array[0].resize(N);
    sumInfo[0].resize(N+1);
    for(int i=0;i<N;i++)
    {
        cin >> array[0][i];
        sumInfo[0][i]=0;
    }
    cin >> M;
    array[1].resize(M);
    sumInfo[1].resize(M+1);
    for(int i=0;i<M;i++)
    {
        cin >> array[1][i];
        sumInfo[1][i]=0;
    }

    unordered_map<int,int> arraySum[2];
    MakeSumInfo(array[0], sumInfo[0], 0, arraySum[0]);
    MakeSumInfo(array[1], sumInfo[1], 0, arraySum[1]);

    long long result=0;
    for(const pair<int,int> datas : arraySum[0])
    {
        result += static_cast<long long>(datas.second) * static_cast<long long>(arraySum[1][T-datas.first]);
    }
    cout << result;
}