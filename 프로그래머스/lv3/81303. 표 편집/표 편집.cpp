#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> table;
vector<pair<int,int>> links;
vector<int> backups;
int dataCnt;

int remove(int k)
{
    backups.push_back(k);
    table[k]=0;
    int nextk = links[k].second;
    if(nextk==-1)
    {
        nextk = links[k].first;
    }
    
    if( links[k].first != -1) links[links[k].first].second = links[k].second;
    if( links[k].second != -1) links[links[k].second].first = links[k].first;
    
    return nextk;
}

void rollback()
{
    if(!backups.empty())
    {
        int idx = backups[backups.size()-1];
        table[idx]=1;
        backups.pop_back();
        
        if(links[idx].first!=-1) links[links[idx].first].second = idx;
        if(links[idx].second!=-1) links[links[idx].second].first = idx;
    }
}

int move(int moveCnt, int k)
{
    if(moveCnt>0)
    {
        while(links[k].second != -1 && moveCnt != 0)
        {
            k = links[k].second;
            moveCnt--;
        }
//         while(moveCnt!=0 && k<dataCnt-1)
//         {
//             if(table[k+1]!=0)
//             {
//                 moveCnt--;
//             }
//             k++;
//         }
        
//         if(k==dataCnt-1)
//         {
//             while(table[k]==0)
//             {
//                 k--;
//             }
//         }
    }
    else
    {
        while(links[k].first != -1 && moveCnt != 0)
        {
            k = links[k].first;
            moveCnt++;
        }
        // while(moveCnt!=0 && k>0)
        // {
        //     if(table[k-1] != 0)
        //     {
        //         moveCnt++;
        //     }
        //     k--;
        // }
        // if(k==0)
        // {
        //     while(table[k]==0)
        //     {
        //         k++;
        //     }
        // }
    }
    return k;
}
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for(int i=0;i<n;i++)
    {
        table.push_back(1);
        if(i==n-1)
        {
            links.push_back({i-1,-1});
        }
        else
        {
            links.push_back({i-1,i+1});
        }
    }
    dataCnt=n;

    int moveCnt = 0;
    for(string& str : cmd)
    {
        if(str[0] == 'C')
        {
            k = move(moveCnt, k);
            k = remove(k);
            moveCnt=0;
        }
        else if(str[0] == 'Z')
        {
            k = move(moveCnt, k);
            moveCnt=0;
            rollback();
        }
        else if(str[0]=='U')
        {
            int val = stoi(str.substr(2));
            moveCnt -= val;
        }
        else if(str[0]=='D')
        {
            int val = stoi(str.substr(2));
            moveCnt += val;
        }
    }

    for(int i=0;i<n;i++)
    {
        if( 0 == table[i] )
        {
            answer += "X";
        }
        else
        {
            answer += "O";
        }
    }
    return answer;
}