#include <iostream>
#include <vector>

using namespace std;


int binary_search(vector<int>& maxVal4EachCnt, int val)
{
    if(maxVal4EachCnt.empty())
    {
        return -1;
    }
    else if(maxVal4EachCnt.back() < val)
    {
        return -1;
    }
    else
    {
        int position = 0x7fffffff;
        int start = 0;
        int end = maxVal4EachCnt.size()-1;
        int mid;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(maxVal4EachCnt[mid]<val)
            {
                start=mid+1;
            }
            else
            {
                position = min(position,mid);
                end=mid-1;
            }
        }
        return position;
    }
}


int main()
{
    int N;
    cin >> N;
    vector<int> val(N);
    for(int i=0;i<N;i++)
    {
        cin >> val[i];
    }

    vector<int> maxVal4EachCnt;
    for(int i=0;i<N;i++)
    {
        int position = binary_search(maxVal4EachCnt, val[i]);
        if(position == -1)
        {
            maxVal4EachCnt.push_back(val[i]);
        }
        else
        {
            maxVal4EachCnt[position] = val[i];
        }
    }
    cout << maxVal4EachCnt.size();
} 