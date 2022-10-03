#include <iostream>

using namespace std;
int numbers[101][10];

int main()
{
    int N;
    cin >> N;
    numbers[0][0] = 0;
    for(int i=1;i<=9;i++)
    {
        numbers[0][i]=1;
    }

    for(int i=1;i<N;i++)
    {
        for(int number=0;number<=9;number++)
        {
            if( number == 0 )
            {
                numbers[i][number]=numbers[i-1][number+1];
            }
            else if(number == 9 )
            {
                numbers[i][number]=numbers[i-1][number-1];    
            }
            else
            {
                numbers[i][number]=(numbers[i-1][number-1])%1000000000;
                numbers[i][number]+=(numbers[i-1][number+1])%1000000000;
                numbers[i][number]%=1000000000;
            }  
        }
    }

    int result = 0;
    for(int i=0;i<=9;i++)
    {
        result = (result+numbers[N-1][i])%1000000000;
    }
    cout << result;
}