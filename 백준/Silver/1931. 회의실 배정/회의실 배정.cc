#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> meetingList(N);
    for(int i=0;i<N;i++)
    {
        cin >> meetingList[i].second >> meetingList[i].first;
    }

    sort(meetingList.begin(), meetingList.end());

    int meetingCnt = 0;
    int lastTime=-1;
    for(int i=0;i<N;i++)
    {
        if( lastTime <= meetingList[i].second)
        {
            lastTime = meetingList[i].first;
            meetingCnt++;
        }
    }
    cout << meetingCnt;
}