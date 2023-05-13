#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number : numbers)
    {
        long long baseVal = 1;
        for(long long i=0;i<51;i++)
        {
            if((number &( baseVal <<i)) == 0)
            {
                if(i == 0)
                {
                    answer.push_back(number+baseVal);
                }
                else
                {
                    answer.push_back(number+(baseVal<<(i-1)));
                }
                break;
            }
        }
        
    }
    return answer;
}