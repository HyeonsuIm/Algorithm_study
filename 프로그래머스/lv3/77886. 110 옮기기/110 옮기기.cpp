#include <string>
#include <vector>

using namespace std;

void MakeBestNumber(string& s)
{
    int cnt=0;
    string str;
    for(int i=s.length()-3;i>=0;i--)
    {
        if(s.substr(i,3) == "110")
        {
            str += "110";
            s = s.erase(i,3);
        }
    }

    bool isFind = false;
    int insertIdx = 0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            insertIdx = i+1;
            break;
        }
    }
    s.insert(insertIdx, str);
}

vector<string> solution(vector<string> s) {
    for(string& str : s)
    {
        MakeBestNumber(str);
    }
    return s;
}