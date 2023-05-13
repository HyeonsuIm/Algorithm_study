#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int,int>> traffics;
    for(string& str : lines)
    {
        istringstream ss(str.substr(11));
        string hour,minute, seconds, miliSeconds, take;
        getline(ss, hour, ':');
        getline(ss, minute, ':');
        getline(ss, seconds, '.');
        getline(ss, miliSeconds, ' ');
        getline(ss, take, 's');

        int finishTime = (stoi(hour)*3600 + stoi(minute)*60 + stoi(seconds))*1000 + stoi(miliSeconds);
        int startTime = finishTime - stof(take)*1000+1;
        traffics.push_back({startTime, finishTime});
    }

    sort(traffics.begin(), traffics.end());
    for(pair<int,int>& traffic : traffics)
    {
        while(!pq.empty())
        {
            if( traffic.first - 999 > pq.top() ) pq.pop();
            else break;
        }
        pq.push(traffic.second);
        answer = max(static_cast<int>(pq.size()),answer);
    }
    return answer;
}