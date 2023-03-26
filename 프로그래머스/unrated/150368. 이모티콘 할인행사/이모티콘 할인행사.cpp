#include <string>
#include <vector>

using namespace std;

int isBetterLhs(vector<int>& lhs, vector<int>& rhs)
{
    if(lhs[0] > rhs[0])
    {
        return true;
    }
    else if(lhs[0] < rhs[0])
    {
        return false;
    }
    else
    {
        return lhs[1] > rhs[1];
    }
}

void MakeResult(const vector<vector<int>> users, const vector<pair<int,int>>& emoticons, vector<int>& result)
{
    int emoticonPrice[5] = {0,0,0,0,0};
    for(int i=0;i<emoticons.size();i++)
    {
        emoticonPrice[emoticons[i].second/10] += emoticons[i].first * (100 - emoticons[i].second) / 100;
    }

    for(int i=3;i>=0;i--)
    {
        emoticonPrice[i] += emoticonPrice[i+1];
    }

    int memberCnt = 0;
    int price = 0;
    for(int i=0;i<users.size();i++)
    {
        int saleIdx = (users[i][0] - 1) / 10 + 1;
        if( emoticonPrice[saleIdx] >= users[i][1])
        {
            memberCnt++;
        }
        else
        {
            price+=emoticonPrice[saleIdx];
        }
    }

    vector<int> resultTemp;
    resultTemp.push_back(memberCnt);
    resultTemp.push_back(price);
    if(isBetterLhs(resultTemp, result))
    {
        result=resultTemp;
    }
}

void dfs(const vector<vector<int>>& users, vector<pair<int,int>>& emoticons, int depth, vector<int>& result)
{
    if(depth==emoticons.size())
    {
        MakeResult(users, emoticons, result);
        return;
    }

    for(int sale=40;sale>=0;sale-=10)
    {
        emoticons[depth].second=sale;
        dfs(users,emoticons,depth+1,result);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2,0);
    vector<pair<int,int>> emoticonsWithSale;
    for(int emoticonPrice : emoticons) emoticonsWithSale.push_back({emoticonPrice, 0});
    
    dfs(users, emoticonsWithSale, 0, answer);
    return answer;
}