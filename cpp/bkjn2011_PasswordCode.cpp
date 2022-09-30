#include <iostream>

using namespace std;

int dp[5001];

int checkPossibleCases(char a, char b)
{
    int val = int(a-'0') * 10 + int(b-'0');
    int val2 = int(b-'0');
    int caseCnt = 0;
    if( val >= 10 && val <= 26)
    {
        caseCnt = 2;
    }
    return caseCnt;
}

int main()
{
    string str;
    cin >> str;
    if(str.length() == 1)
    {
        if( str[0] == '0' )
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
    else
    {
        dp[0] = 1;
        for(int i=0;i<str.length();i++)
        {
            if( i == 0)
            {
                if(str[i] >= '1' && str[i] <='9')
                {
                    dp[i+1] = dp[i+1] + dp[i];
                }
                else
                {
                    cout << 0;
                    return 0;
                }
            }
            else
            {
                if(str[i] >= '1' && str[i] <='9')
                {
                    dp[i+1]=(dp[i+1]+dp[i]) % 1000000;
                }

                int val = (str[i-1]-'0')*10+str[i]-'0';
                if(val >= 10 && val <=26)
                {
                    dp[i+1]=(dp[i+1]+dp[i-1]) % 1000000;
                }

                if(val == 0)
                {
                    cout << 0;
                    return 0;
                }
            }
        }
        cout << dp[str.length()];
    }
}