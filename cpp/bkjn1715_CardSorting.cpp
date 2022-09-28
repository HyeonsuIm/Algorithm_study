#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    int val;
    for(int i=0;i<N;i++)
    {
        cin >> val;
        pq.push(val);
    }

    int result = 0;
    while(pq.size() != 1)
    {
        int val1 = pq.top();
        pq.pop();    
        int val2 = pq.top();
        pq.pop();
        result += val1+val2;
        pq.push(val1+val2);
    }

    cout <<result;
}