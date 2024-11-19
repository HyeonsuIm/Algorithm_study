from sys import stdin
from heapq import heappop, heappush

next = [
    [-1, -1],
    [-1,  0],
    [-1,  1],
    [ 0, -1],
    [ 0,  1],
    [ 1, -1],
    [ 1,  0],
    [ 1,  1]
]

N, M, K= map(int,stdin.readline().split())
map = [str(stdin.readline().strip()) for _ in range(N)]
find_str = [str(stdin.readline().strip()) for _ in range(K)]

def move_coord(y,x,yDiff,xDiff):
    next_x = x+xDiff
    if next_x < 0:
        next_x = M-1
    elif next_x >= M:
        next_x = 0
        
    next_y = y+yDiff
    if next_y < 0:
        next_y = N-1
    elif next_y >= N:
        next_y = 0
    return next_x, next_y

def check_str(y, x, str, idx):
    count=0
    if map[y][x] == str[idx]:
        if idx == len(str)-1:
            count = 1
        else:
            for yDiff, xDiff in next:
                nextx, nexty = move_coord(y,x,yDiff, xDiff)
                count += check_str(nexty,nextx, str, idx+1)
    return count

dict = {}
for str in find_str:
    count = 0
    if str in dict.keys():
        count = dict[str]
    else:
        for x in range(M):
            for y in range(N):
                count += check_str(y,x,str,0)
        dict[str] = count
    print(count)