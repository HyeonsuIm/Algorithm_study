#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<pair<int,int>>> subsequences;
    for(int i=0;i<N;i++)
    {
        int val;
        cin >> val;
        int j=0;
        for(;j<subsequences.size();j++)
        {
            if( subsequences[j].rbegin()->first >= val )
            {
                subsequences[j].push_back(make_pair(val, i));
                break;
            }
        }

        if( j == subsequences.size())
        {
            subsequences.push_back(vector<pair<int,int>>());
            subsequences.rbegin()->push_back(make_pair(val, i));
        }
    }

    vector<int> values;
    auto iterSubsequence = subsequences.rbegin();
    int index = N;
    for(;iterSubsequence != subsequences.rend();iterSubsequence++)
    {
        auto iterValues = iterSubsequence->rbegin();
        for(;iterValues != iterSubsequence->rend();iterValues++)
        {
            if(iterValues->second < index)
            {
                values.push_back(iterValues->first);
                index = iterValues->second;
                break;
            }
        }
    }

    cout << values.size() << endl;
    for(int i=values.size()-1;i>=0;i--)
    {
        cout << values[i] << " ";
    }
}