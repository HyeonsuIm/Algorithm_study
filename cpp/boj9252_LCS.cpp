#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
    string A,B;
    cin >> A >> B;
    int** compareArr = new int*[B.length()+1];
    for(int i=0;i<B.length()+1;i++)
    {
        compareArr[i] = new int[A.length()+1];
        memset(compareArr[i], 0, sizeof(int)*(A.length()+1));
    }
    
    for(int i=1;i<B.length()+1;i++)
    {
        for(int j=1;j<A.length()+1;j++)
        {
            int maxVal = max(compareArr[i-1][j], compareArr[i][j-1]);
            if(B[i-1] == A[j-1])
            {
                compareArr[i][j] = max(maxVal, compareArr[i-1][j-1]+1);
            }
            else
            {
                compareArr[i][j] = maxVal;
            }
        }
    }

    int cnt = compareArr[B.length()][A.length()];
    cout << cnt << endl;
    int lastX = A.length();
    int lastY = B.length();
    string dataList;
    for(int i=0;i<cnt;i++)
    {
        for(;lastX>1;lastX--)
        {
            if(compareArr[lastY][lastX] != compareArr[lastY][lastX-1])
            {
                break;
            }
        }
        for(;lastY>1;lastY--)
        {
            if(compareArr[lastY][lastX] != compareArr[lastY-1][lastX])
            {
                break;
            }
        }
        dataList+=B[lastY-1];
        lastY -=1;
        lastX -=1;
    }

    for(int i=dataList.length()-1;i>=0;i--)
    {
        cout << dataList[i];
    }
    
    for(int i=0;i<B.length();i++)
    {
        delete[] compareArr[i];
    }
    delete [] compareArr;
}