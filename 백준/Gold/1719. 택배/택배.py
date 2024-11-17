from sys import stdin
from heapq import heappop, heappush

n, m = map(int,stdin.readline().split())
def bfs(graph, start, result):
    from_result = [0 for _ in range(n+1)]
    heap = []
    insert_order = 0
    for node in graph[start]:
        heappush(heap, (node[1], insert_order, node[0], node[0]))
        insert_order +=1
        
    while heap:
        cost, _, curr, fr = heappop(heap)
        if from_result[curr] != 0:
            continue
        
        from_result[curr] = fr
        for next, time in graph[curr]:
            if from_result[next] == 0:
                heappush(heap, (cost+time, insert_order, next, fr))
                insert_order +=1
    
    result[start] = [str(fr) for fr in from_result]
    result[start][start] = '-'

graph = [[] for _ in range(n+1)]
for _ in range(m):
    fr, to, t = map(int, stdin.readline().split())
    graph[fr].append([to, t])
    graph[to].append([fr, t])

result = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    bfs(graph, i, result)

for i in range(1,n+1):
    print(*result[i][1:], sep=' ')