#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> values(N);
    int sum =-1001;
    int maxSum = -1001;
    for(int i=0;i<N;i++)
    {
        cin >> values[i];
        sum = max(sum+values[i], values[i]);
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
}