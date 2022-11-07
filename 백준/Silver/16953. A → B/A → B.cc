#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    int count = 0;
    while(true)
    {
        if( b > a)
        {
            count+=1;
            if(b%2 == 0)
            {
                b/=2;
            }
            else
            {
                if( b % 10 == 1)
                {
                    b -=1;
                    b/=10;
                }
                else
                {
                    count = -1;
                    break;
                }
            }
        }
        else if(b == a)
        {
            count += 1;
            break;
        }
        else
        {
            count = -1;
            break;
        }
    }

    cout << count;
}