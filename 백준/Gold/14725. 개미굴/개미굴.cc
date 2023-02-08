#include <iostream>
#include <vector>
#include <map>
#include "math.h"

using namespace std;

struct node
{
    map<string, node*> childs;
};

void PrintNode(node* pNode, int depth)
{
    for(pair<const string,node*> childNode : pNode->childs)
    {
        for(int i=0;i<depth;i++)
        {
            cout << "--";
        }
        cout << childNode.first << endl;
        PrintNode(childNode.second, depth+1);
    }  
}

int main()
{
    ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);
    int n;
    cin >> n;
    node root;
    for(int i=0;i<n;i++)
    {
        int cnt;
        cin >> cnt;
        int treeIdx = 1;
        node* pCurrNode = &root;
        for(int j=0;j<cnt;j++)
        {
            string str;
            cin >> str;
            auto childIter = pCurrNode->childs.find(str);
            if(childIter == pCurrNode->childs.end())
            {
                node* newNode = new node;
                pCurrNode->childs.insert({str, newNode});
                pCurrNode = newNode;
            }
            else
            {
                pCurrNode = childIter->second;
            }
        }
    }

    PrintNode(&root, 0);
}