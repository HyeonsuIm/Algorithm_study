#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int MakeMap(const vector<int>& list, unordered_map<int,int>& map)
{
    int lastIdx=0;
    for(int i=0;i<list.size();i++)
    {
        if(i==0)
        {
            map[list[i]]=lastIdx;
        }
        else
        {
            if(list[i-1]==list[i])
            {
                map[list[i]]=lastIdx;
            }
            else
            {
                map[list[i]]=++lastIdx;
            }
        }
    }
    return lastIdx+1;
}

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    vector<int> xList, yList;
    for(int i=0;i<data.size();i++)
    {
        xList.push_back(data[i][0]);
        yList.push_back(data[i][1]);
    }
    sort(xList.begin(),xList.end());
    sort(yList.begin(),yList.end());
    unordered_map<int,int> xMap, yMap;
    int xSize = MakeMap(xList,xMap);
    int ySize = MakeMap(yList,yMap);
    
    vector<vector<bool>> map(xSize);
    vector<vector<int>> dp(xSize+1);
    dp[0].assign(ySize+1,0);
    for(int i=0;i<xSize;i++)
    {
        map[i].assign(ySize,false);
        dp[i+1].assign(ySize+1,0);
    }
    
    for(int i=0;i<data.size();i++)
    {
        map[xMap[data[i][0]]][yMap[data[i][1]]] = true;
    }
    
    for(int x=0;x<xSize;x++)
    {
        for(int y=0;y<ySize;y++)
        {
            dp[x+1][y+1] = dp[x][y+1] + dp[x+1][y]-dp[x][y];
            dp[x+1][y+1] += map[x][y] ? 1:0;
        }
    }
    
    for(int i=0;i<data.size();i++)
    {
        for(int j=i+1;j<data.size();j++)
        {
            if(data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            int minX = xMap[min(data[i][0], data[j][0])], maxX = xMap[max(data[i][0], data[j][0])];
            int minY = yMap[min(data[i][1], data[j][1])], maxY = yMap[max(data[i][1], data[j][1])];
            int count = dp[maxX][maxY] - dp[maxX][minY+1] - dp[minX+1][maxY] + dp[minX+1][minY+1];
            if( count == 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}