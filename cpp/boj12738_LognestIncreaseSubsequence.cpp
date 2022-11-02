#include <iostream>
#include <vector>

using namespace std;

int Search(vector<int>& list, int val, int start, int end)
{
    if( list[end] < val)
    {
        return -1;
    }

    if( start==end )
    {
        return end;
    }

    int mid = (start+end)/2;
    if(list[mid] < val)
    {
        return Search(list, val, mid+1, end);
    }
    else
    {
        return Search(list, val, start,mid);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> bestSubsequences;
    for(int i=0;i<N;i++)
    {
        int val, j;
        scanf("%d", &val);
        if(!bestSubsequences.empty())
        {
            int result = Search(bestSubsequences, val, 0, bestSubsequences.size()-1);
            if(-1 == result)
            {
                bestSubsequences.push_back(val);
            }
            else
            {
                bestSubsequences[result] = val;
            }
        }
        else
        {
            bestSubsequences.push_back(val);
        }
    }

    printf("%lu",bestSubsequences.size());
}