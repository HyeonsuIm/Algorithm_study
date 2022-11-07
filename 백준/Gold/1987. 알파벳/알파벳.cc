#include <stdio.h>
#include <iostream>
#include <vector>

int GetBestCnt(const std::vector<std::string>& map, int maxRow, int maxCol, std::vector<bool>& usedArr, int positionRow, int positionCol, int depth)
{
    if (positionRow < 0 || 
        positionCol < 0 ||
        positionRow >= maxRow ||
        positionCol >= maxCol ||
        usedArr[map[positionRow][positionCol]-'A'] == true)
    {
        return 0;
    }
    else
    {
        usedArr[map[positionRow][positionCol]-'A'] = true;
        
        int result = 0;
        result = std::max(result,GetBestCnt(map, maxRow, maxCol, usedArr, positionRow+1, positionCol, depth+1));
        result = std::max(result,GetBestCnt(map, maxRow, maxCol, usedArr, positionRow-1, positionCol, depth+1));
        result = std::max(result,GetBestCnt(map, maxRow, maxCol, usedArr, positionRow, positionCol+1, depth+1));
        result = std::max(result,GetBestCnt(map, maxRow, maxCol, usedArr, positionRow, positionCol-1, depth+1));
        usedArr[map[positionRow][positionCol]-'A'] = false;

        return std::max(depth, result);
    }
}


int main()
{
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> map(R);
    for( int i = 0 ; i < R ; i++)
    {
        std::cin >> map[i];
    }

    std::vector<bool> usedArr('Z'-'A'+1,false);
    printf("%d", GetBestCnt(map, R, C, usedArr, 0, 0, 1));
    return 0;
}