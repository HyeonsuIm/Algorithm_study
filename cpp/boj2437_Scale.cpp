#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> weightList(N);
    for(int i=0;i<N;i++)
    {
        cin >> weightList[i];
    }
    sort(weightList.begin(), weightList.end());
    int sum = 0;
    for(int i=0;i<weightList.size();i++)
    {
        if(weightList[i] > sum+1)
        {
            break;
        }
        else
        {
            sum += weightList[i];
        }
    }
    cout << sum+1;
}