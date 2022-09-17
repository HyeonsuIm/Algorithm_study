"""bkjn 14502 problem solve"""
from sys import stdin
from copy import deepcopy


def make_virus(map, N, M, y, x):
    if x >= M or x < 0 or y >= N or y < 0:
        return

    if map[y][x] != 0 :
        return

    map[y][x] = 2
    make_virus(map, N, M, y+1, x)
    make_virus(map, N, M, y-1, x)
    make_virus(map, N, M, y, x+1)
    make_virus(map, N, M, y, x-1)


def get_safe_area(map, N, M):
    temp_map = deepcopy(map)
    for i in range(N):
        for j in range(M):
            if 2 == temp_map[i][j]:
                make_virus(temp_map, N, M, i+1, j)
                make_virus(temp_map, N, M, i-1, j)
                make_virus(temp_map, N, M, i, j+1)
                make_virus(temp_map, N, M, i, j-1)


    safe_area = 0
    for i in range(N):
        for j in range(M):
            if temp_map[i][j] == 0:
                safe_area+=1
    return safe_area


N, M = map(int,stdin.readline().split())
lab = []
for _ in range(N):
    lab.append(list(map(int,stdin.readline().split())))

safe_cnt = 0
for x in range(M):
    for y in range(N):
        if lab[y][x] == 0:
            safe_cnt += 1

MAX_SAFE_AREA = safe_cnt - 3


SAFE_AREA = 0
for y1 in range(N):
    for x1 in range(M):
        if lab[y1][x1] != 0: 
            continue
        lab[y1][x1] = 1
        for y2 in range(y1,N):
            startX2 = x1 + 1 if y2 == y1 else 0
            for x2 in range(startX2,M):
                if lab[y2][x2] != 0:
                    continue

                lab[y2][x2] = 1
                for y3 in range(y2,N):
                    startX3 = x2 + 1 if y3 == y2 else 0
                    for x3 in range(startX3,M):
                        if lab[y3][x3] != 0:
                            continue

                        lab[y3][x3] = 1
                        TEMP = get_safe_area(lab, N, M)
                        if SAFE_AREA < TEMP:
                            SAFE_AREA = TEMP
                        
                        if MAX_SAFE_AREA == SAFE_AREA:
                            print(SAFE_AREA)
                            exit()
                        lab[y3][x3] = 0
                lab[y2][x2] = 0
        lab[y1][x1] = 0

print(SAFE_AREA)