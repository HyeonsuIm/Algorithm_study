from sys import stdin
from heapq import heappush, heappop
from math import inf

N, K = map(int,stdin.readline().split())

if K <= N:
    print(N-K)
else:
    expand_info = [inf for _ in range(200001)]
    heap = []
    heappush(heap, [0, N])
    RESULT = 0
    while heap:
        cost, position = heappop(heap)
        if position == K:
            RESULT = cost
            break
        
        if expand_info[position] <= cost:
            continue

        expand_info[position] = cost
        if position < K:
            heappush(heap, [cost+1, position+1])
            heappush(heap, [cost, position*2])
        
        if position != 0:
            heappush(heap, [cost+1, position-1])
    
    print(RESULT)