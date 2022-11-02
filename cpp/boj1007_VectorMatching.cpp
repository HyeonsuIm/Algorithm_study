#include <iostream>
#include <vector>
#include <unordered_map>
#include <float.h>
#include <math.h>

using namespace std;

bool isPlus[20];

double GetBestCase(vector<pair<int,int>>& nodes, int depth, int plusCount)
{
    if( depth >= nodes.size() ||
        depth-plusCount > nodes.size()/2)
    {
        return DBL_MAX;
    }

    if( plusCount == nodes.size()/2)
    {
        int x=0;
        int y=0;
        for(int i=0;i<nodes.size();i++)
        {
            if( isPlus[i] == true )
            {
                x += nodes[i].first;
                y += nodes[i].second;
            }
            else
            {
                x -= nodes[i].first;
                y -= nodes[i].second;
            }
        }

        return sqrt(static_cast<double>(pow(x,2)) + static_cast<double>(pow(y,2)));
    }
    
    isPlus[depth]=true;
    double minimum = GetBestCase(nodes, depth+1, plusCount+1);
    isPlus[depth]=false;
    minimum = min(minimum, GetBestCase(nodes, depth+1, plusCount));
    return minimum;
}


int main()
{
    int t;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        int N;

        cin >> N;

        vector<pair<int,int>> nodes(N);
        for(int j=0;j<N;j++)
        {
            cin >> nodes[j].first >> nodes[j].second;
        }

        printf("%lf\n", static_cast<double>(GetBestCase(nodes, 0, 0)));
    }
}