#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C, totalaeiou;

void dfs(vector<char>& str, string curr, int depth, int position, int aeiouCnt)
{
    if( depth == L)
    {
        if(aeiouCnt >= 1 && L - aeiouCnt >= 2)
        {
            cout << curr << endl;
        }
        return;
    }

    for(int i=position;i<C;i++)
    {
        if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] =='u' )
        {
            dfs(str, curr + str[i], depth+1, i+1, aeiouCnt+1);    
        }
        else
        {
            dfs(str, curr + str[i], depth+1, i+1, aeiouCnt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> L >> C;

    vector<char> str(C);
    for(int i=0;i<C;i++)
    {
        cin >> str[i];
    }

    sort(str.begin(),str.end());
    dfs(str, "", 0, 0, 0);

    return 0;
}