from sys import stdin
from heapq import heappush, heappop
from math import inf

N, K = map(int,stdin.readline().split())

if K <= N:
    print(N-K)
    print(1)
else:
    expand_info = [[inf,0] for _ in range(200001)]
    heap = []
    heappush(heap, [0, N, -1])
    RESULT = inf
    BEST_CNT = 0
    while heap:
        cost, position, prev_position = heappop(heap)
        if cost > RESULT:
            break

        if expand_info[position][0] < cost:
            continue
        
        if prev_position == -1:
            expand_info[position][1] += 1
        else:
            expand_info[position][1] += expand_info[prev_position][1]

        if expand_info[position][0] == cost:
            continue

        expand_info[position][0] = cost
        if position == K:
            RESULT = cost
            continue

        if position < K:
            heappush(heap, [cost+1, position+1, position])
            heappush(heap, [cost+1, position*2, position])
        
        if position != 0:
            heappush(heap, [cost+1, position-1, position])
    
    print(RESULT)
    print(expand_info[K][1])