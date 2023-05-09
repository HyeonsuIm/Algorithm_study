#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start=0, mid, end = *max_element(stones.begin(), stones.end());
    while(start!=end)
    {
        mid = (start+end)/2;
        int maxSkipCnt=0;
        int skipCnt=0;
        for(int i=0;i<stones.size();i++)
        {
            if( mid >= stones[i] ) 
            {
                skipCnt++;
            }
            else
            {
                maxSkipCnt = max(skipCnt, maxSkipCnt);
                skipCnt=0;
            }
        }
        maxSkipCnt = max(skipCnt, maxSkipCnt);
        if(k <= maxSkipCnt) end = mid;
        else start = mid+1;
    }
    
    return start;
}