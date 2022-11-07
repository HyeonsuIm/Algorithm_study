#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    bool isFail = false;
    int count=0;
    while(N>=3 && N%5 != 0)
    {
        N-=3;
        count +=1;
    }

    if(N<0 || N%5 != 0)
    {
        cout << -1;
    }
    else
    {
        cout << count+N/5;
    }
}