#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int N, val;
    cin >> N;
    vector<int> values(N);
    for(int i=0;i<N;i++)
    {
        cin >> values[i];
    }

    sort(values.begin(), values.end());
    int value[2];
    int idxFromStart = 0;
    int idxFromLast = values.size()-1;
    int minDiff=0x7fffffff;
    while(idxFromStart != idxFromLast)
    {
        int diff = values[idxFromStart] + values[idxFromLast];
        if( abs(diff) <= minDiff )
        {
            minDiff = abs(diff);
            value[0] = values[idxFromStart];
            value[1] = values[idxFromLast];

            if( minDiff == 0)
            {
                break;
            }
        }

        if(diff > 0)
        {
            idxFromLast-=1;
        }
        else
        {
            idxFromStart+=1;
        }
    }
    cout << value[0] << " " << value[1];
}