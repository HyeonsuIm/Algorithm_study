#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int valueSize;

bool CheckSwapValues(set<string>& valueList)
{
    queue<string> q;
    for(const string& str : valueList)
    {
        q.push(str);
    }
    valueList.clear();

    while(!q.empty())
    {
        string str = q.front();
        q.pop();

        for(int i=0;i<valueSize-1;i++)
        {
            for(int j=i+1;j<valueSize;j++)
            {
                if(i==0 && str[j] == '0') continue;

                swap(str[i], str[j]);
                if( valueList.find(str) == valueList.end() )
                {
                    valueList.insert(str);
                }
                swap(str[i], str[j]);
            }
        }
    }

    if(valueList.empty())
        return false;
    else
        return true;
}

int main()
{
    string val;
    int K;
    cin >> val >> K;
    valueSize = val.length();

    set<string> valueList;
    valueList.insert(val);
    
    bool result = true;
    for(int i=0;i<K && result;i++)
    {
        result = CheckSwapValues(valueList);
    }

    if(result) cout << *max_element(valueList.begin(), valueList.end());
    else cout << -1;
}