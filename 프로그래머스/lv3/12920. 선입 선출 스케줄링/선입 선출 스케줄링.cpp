#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    if( n < cores.size() ) return n;
    n-=cores.size();
    int max = *max_element(cores.begin(), cores.end());
    int start=0,end=max*n, mid;
    int selectedCnt = 0;
    while(start!=end)
    {
        mid = (start+end)/2;
        int cnt=0;
        for(int i=0;i<cores.size();i++)
        {
            cnt += mid / cores[i];
        }
        
        if( cnt >= n )
        {
            end = mid;
        }
        else
        {
            start = mid+1;
        }
    }
    
    for(int i=0;i<cores.size();i++)
    {
        n -= (start-1)/cores[i];
    }
    
    int result = 0;
    for(int i=0;i<cores.size();i++)
    {
        if(start % cores[i] == 0)
        {
            n--;
            if( n == 0)
            {
                result= i+1;
                break;
            }
        }
    }
    
    return result;
}