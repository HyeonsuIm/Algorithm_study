#include <iostream>

using namespace std;

#define MOD_NUM 10007

int numbers[1001][10];

int main()
{
    int N;
    cin >> N;
    for(int i=0;i<=9;i++)
    {
        numbers[0][i] = 1;
    }

    for(int i=1;i<N;i++)
    {
        numbers[i][0] = numbers[i-1][0];
        for(int j=1;j<10;j++)
        {
            numbers[i][j] = (numbers[i][j-1] + numbers[i-1][j])%MOD_NUM;
        }
    }

    int result = 0;
    for(int i=0;i<=9;i++)
    {
        result = (result + numbers[N-1][i])%MOD_NUM;
    }
    cout << result;
}