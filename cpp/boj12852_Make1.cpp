#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int N;
    cin >> N;
    queue<tuple<int,int,int>> q;
    vector<pair<int,int>> expandList;
    q.push(make_tuple(1,N,-1));
    while(!q.empty())
    {
        tuple<int,int,int>& data = q.front();
        
        int depth = get<0>(data);
        int value = get<1>(data);
        int parent = get<2>(data);
        q.pop();
        expandList.push_back(make_pair(value, parent));
        if(value == 1)
        {
            break;
        }
        parent = expandList.size()-1;
        if(value % 3 == 0)
        {
            q.push(make_tuple(depth+1, value/3,parent));
        }
        if(value % 2 == 0)
        {
            q.push(make_tuple(depth+1, value/2,parent));
        }
        q.push(make_tuple(depth+1, value-1,parent));
    }

    vector<int> dataList;
    int idx = expandList.size()-1;
    while(idx != -1)
    {
        dataList.push_back(expandList[idx].first);
        idx = expandList[idx].second;
    }

    cout << dataList.size()-1 << endl;
    for(int i=dataList.size()-1;i>=0;i--)
    {
        cout << dataList[i] << " ";
    }
}