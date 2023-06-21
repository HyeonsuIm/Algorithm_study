#include <iostream>

using namespace std;

long long result[10];

void addNumCnt(long long n, long long digitCnt)
{
    while(n>0)
    {
        result[n%10] += digitCnt;
        n/=10;
    }
}

void Search(long long start, long long end)
{
    long long digitCnt = 1;
    while(true)
    {
        while(start%10!=0 && start<=end)
        {
            addNumCnt(start, digitCnt);
            start++;
        }

        while(end%10!=9 && start<=end)
        {
            addNumCnt(end, digitCnt);
            end--;
        }

        if (start > end) break;
        long long valueCnt = (end/10 - start/10 + 1);
        for(int i=0;i<=9;i++)
        {
            result[i] += valueCnt*digitCnt;
        }
        start/=10;
        end/=10;
        digitCnt*=10;
    }
}

int main()
{
    long long N;
    cin >> N;
    Search(1,N);
    for(int i=0;i<=9;i++)
    {
        cout << result[i] << " ";
    }
}