#include <iostream>

using namespace std;

int dpMax[2][3];
int dpMin[2][3];

int main()
{
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        dpMax[0][0] = dpMax[1][0];
        dpMax[0][1] = dpMax[1][1];
        dpMax[0][2] = dpMax[1][2];

        dpMin[0][0] = dpMin[1][0];
        dpMin[0][1] = dpMin[1][1];
        dpMin[0][2] = dpMin[1][2];
        int values[3];
        cin >> values[0] >> values[1] >> values[2];
        dpMax[1][0] = max(dpMax[0][0], dpMax[0][1]) + values[0];
        dpMax[1][1] = max(dpMax[0][2], max(dpMax[0][1],dpMax[0][0])) + values[1];
        dpMax[1][2] = max(dpMax[0][2], dpMax[0][1]) + values[2];

        dpMin[1][0] = min(dpMin[0][0], dpMin[0][1]) + values[0];
        dpMin[1][1] = min(dpMin[0][2], min(dpMin[0][1],dpMin[0][0])) + values[1];
        dpMin[1][2] = min(dpMin[0][2], dpMin[0][1]) + values[2];
    }

    cout << max(dpMax[1][0], max(dpMax[1][1], dpMax[1][2])) << " " << min(dpMin[1][0], min(dpMin[1][1], dpMin[1][2]));
}