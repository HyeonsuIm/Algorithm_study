#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> points(N);
    for(int i=0;i<N;i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    int selectedI;
    int selectedJ;
    double minDist = 1000000000;
    int bestX;
    int bestY;
    for(int i=0;i<N;i++)
    {
        double maxDist = 0;
        for(int j=0;j<N;j++)
        {
            double dist = pow(points[i].first-points[j].first,2)+pow(points[i].second-points[j].second,2);
            if(maxDist < dist)
            {
                maxDist = dist;
            }
        }
        if(minDist > maxDist)
        {
            minDist = maxDist;
            bestX = points[i].first;
            bestY = points[i].second;
        }
    }
    cout << bestX << " "<<bestY;
}