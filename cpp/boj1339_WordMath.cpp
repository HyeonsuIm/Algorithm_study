#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <math.h>

using namespace std;

#define MAX_ALPHA 10

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> wordDict;

    vector<string> stringList(N);
    vector<pair<int, char>> list(26);
    for(int i=0;i<26;i++)
    {
        list[i].second = i + 'A';
    }
    for(int i=0;i<N;i++)
    {
        cin >> stringList[i];
        for(int j=0;j<stringList[i].length();j++)
        {
            list[int(stringList[i][j]-'A')].first += pow(10, stringList[i].length()-1-j);
        }
    }

    sort(list.begin(), list.end(), greater<pair<int, char>>());
    int val = 9;
    for(int i=0;i<list.size();i++)
    {
        if(list[i].first > 0)
        {
            wordDict[list[i].second] = val--;
        }
        else
        {
            break;
        }
    }

    int result=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<stringList[i].length();j++)
        {
            result += pow(10, stringList[i].length()-1-j) * wordDict[stringList[i][j]];
        }
    }
    cout << result;
}