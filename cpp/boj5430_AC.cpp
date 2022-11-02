#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        string command;
        cin >> command;

        int valCnt;
        cin >> valCnt;

        char temp;
        vector<int> valList(valCnt);
        scanf("\n%c", &temp);
        for(int i=0;i<valCnt-1;i++)
        {
            scanf("%d,", &valList[i]);
        }
        scanf("%d", &valList[valCnt-1]);
        scanf("%c", &temp);

        bool isReverse=false;
        bool isError = false;
        int start = 0;
        int end = valList.size()-1;
        for(int i=0;i<command.length();i++)
        {
            if(command[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if(isReverse)
                {
                    if( end >= 0 && valList[end] != 0)
                    {
                        valList[end--] = 0;
                    }
                    else
                    {
                        isError = true; 
                        break;
                    }
                }
                else
                {
                    if( start < valList.size() && valList[start] != 0)
                    {
                        valList[start++] = 0;
                    } 
                    else
                    {
                        isError = true;
                        break;
                    }
                }
            }
        }
        if( isError )
        {
            cout << "error" << endl;
        }
        else
        {
            vector<int> lastVal;
            if( isReverse )
            {
                for(int i=valList.size()-1;i>=0;i--)
                {
                    if(valList[i] != 0)
                    {
                        lastVal.push_back(valList[i]);
                    }
                }
            }
            else
            {
                for(int i=0;i<valList.size();i++)
                {
                    if(valList[i] != 0)
                    {
                        lastVal.push_back(valList[i]);
                    }
                }
            }
            printf("[");
            if( lastVal.size() >= 1)
            {
                for(int i=0;i<lastVal.size()-1;i++)
                {
                    printf("%d,", lastVal[i]);
                }
                printf("%d",lastVal[lastVal.size()-1]);
            }
            printf("]\n");
        }
    }
}