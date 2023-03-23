#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    vector<int> deliveriesStack;
    vector<int> pickupsStack;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<deliveries[i];j++)
        {
            deliveriesStack.push_back(i+1);
        }
        
        for(int j=0;j<pickups[i];j++)
        {
            pickupsStack.push_back(i+1);
        }
    }
    
    long long moveCnt = 0;
    while(!deliveriesStack.empty() || !pickupsStack.empty())
    {
        int deliver, pickup;
        deliver = deliveriesStack.empty() ? 0 : deliveriesStack.back();
        pickup = pickupsStack.empty() ? 0 : pickupsStack.back();
        
        moveCnt += max(deliver, pickup)*2;
        for(int i=0;i<cap;i++)
        {
            if(!deliveriesStack.empty())deliveriesStack.pop_back();
            if(!pickupsStack.empty())pickupsStack.pop_back();
        }
    }
    
    return moveCnt;
}