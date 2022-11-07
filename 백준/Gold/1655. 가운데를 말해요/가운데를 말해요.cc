#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    for(int i=0;i<N;i++)
    {
        int value;
        scanf("%d",&value);
        if( pq_max.size() > pq_min.size()) pq_min.push(value);
        else pq_max.push(value);

        if( !pq_max.empty() && !pq_min.empty())
        {
            if( pq_max.top() > pq_min.top() )
            {
                int a = pq_max.top();
                int b = pq_min.top();
                pq_max.pop();
                pq_min.pop();
                pq_max.push(b);
                pq_min.push(a);
            }
        }
        printf("%d\n",pq_max.top());
    }
}