#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        string str;
        cin >> str;
        cout << str[0] << str[str.length()-1] << endl;
    }
}