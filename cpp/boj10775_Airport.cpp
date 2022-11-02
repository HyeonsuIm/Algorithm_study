#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool insertTree(vector<int>& tree, int position, int treeNode, int start, int end)
{
    bool result = true;
    if(start == end)
    {
        if( tree[treeNode] == 1) return false;
        else
        {
            tree[treeNode]=1;
            return true;
        }
    }
    else
    {
        // if( end-start+1 == tree[treeNode] )
        // {
        //     return false;
        // }
        int mid = (start+end)/2;
        if( position >= start && position <= mid)
        {
            result=insertTree(tree, position, treeNode*2, start, mid);
        }
        else
        {
            result = tree[treeNode*2+1] != end-mid;
            if(result)
            {
                result=insertTree(tree, position, treeNode*2+1, mid+1, end);
            }
            
            if(false == result)
            {
                result=insertTree(tree, mid, treeNode*2, start, mid);
            }
        }
    }

    if(result == true)
    {
        tree[treeNode]+=1;
    }
    return result;
}

int main()
{
    int G, P;
    cin >> G >> P;
    int g;
    vector<int> segment_tree(pow(2,int(log2(G))+2));
    int cnt=0;
    for(int i=0;i<P;i++)
    {
        cin >> g;
        if(insertTree(segment_tree, g-1, 1, 0, G-1))
        {
            cnt+=1;
        }
        else
        {
            break;
        }
    }
    cout << cnt << endl;
}