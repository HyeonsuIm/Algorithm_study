from sys import stdin
from heapq import heappush, heappop


around_point = [\
    [-1,0],\
    [1,0],\
    [0,-1],\
    [0,1]\
]


def expand_around(move_map, cost, x, y, is_break, heap_data):
    """expanding"""
    if x < 0 or y < 0 or x >= N or y >= M:
        return
    
    if is_break is True:
        if move_map[x][y] == 1 :
            heappush(heap_data, [cost, x, y])
    else:
        if move_map[x][y] <= cost and move_map[x][y] != 0:
            return
        move_map[x][y] = cost
        heappush(heap_data, [cost, x, y])


def calculation(move_map, heap_data):
    """calculation the route"""
    while heap_data:
        cost, x, y = heappop(heap_data)
        if x == N-1 and y == M-1:
            break

        for x_diff, y_diff in around_point:
            expand_around(move_map, cost+1, x+x_diff, y+y_diff, False, heap_data)


def break_block(move_map, heap_data):
    """break block"""
    for x in range(N):
        for y in range(M):
            if 1 < move_map[x][y]:
                for x_diff, y_diff in around_point:
                    expand_around(move_map, move_map[x][y]+1, x+x_diff, y+y_diff, True, heap_data)

N, M = map(int, stdin.readline().split())
move_map = [[int(ch) for ch in stdin.readline().rstrip()] for _ in range(N)]

heap_data = []
heappush(heap_data, [2,0,0])
move_map[0][0] = 2
calculation(move_map,heap_data)
break_block(move_map, heap_data)
calculation(move_map, heap_data)

if move_map[N-1][M-1] == 0:
    print(-1)
else:
    print(move_map[N-1][M-1]-1)