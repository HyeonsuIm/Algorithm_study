from sys import stdin
from heapq import heappop, heappush

N = int(stdin.readline())
M = int(stdin.readline())
inflowcnt = [0 for _ in range(N+1)]
inflow = [[] for _ in range(N+1)]
outflow = [[] for _ in range(N+1)]
for _ in range(M):
    X, Y, K = map(int,stdin.readline().split())
    inflowcnt[X] += 1
    inflow[X].append([Y,K])
    outflow[Y].append([X,K])

sorted_list = []
base_idx_list=[]
for i in range(1, N+1):
    if inflowcnt[i] == 0:
        sorted_list.append(i)
        base_idx_list.append(i)

i=0
while len(sorted_list) > i:
    for next, K in outflow[sorted_list[i]]:
        inflowcnt[next]-=1
        if inflowcnt[next] == 0:
            sorted_list.append(next)
    i+=1

result = [0 for _ in range(N+1)]
result[N] = 1
for i in reversed(sorted_list):
    for prev, cnt in inflow[i]:
        result[prev] += result[i] * cnt

base_idx_list.sort()
for i in base_idx_list:
    print(i,result[i])