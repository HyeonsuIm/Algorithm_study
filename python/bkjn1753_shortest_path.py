from sys import stdin
import heapq

V, E = map(int, stdin.readline().split())
K = int(stdin.readline().rstrip())-1

move_path = {}
shortest_path_node = [-1 for _ in range(V)]

for _ in range(E):
    u, v, w = map(int, stdin.readline().split())
    if not move_path.get(u-1):
        move_path[u-1] = []
    
    move_path[u-1].append([v-1,w])

heap = []
heapq.heappush(heap, [0, K])

while heap:
    cost, node = heapq.heappop(heap)

    if -1 == shortest_path_node[node] or shortest_path_node[node] > cost:
        shortest_path_node[node] = cost

        if node not in move_path:
            continue
        for next_node, weight in move_path[node]:
            heapq.heappush(heap, [cost+weight, next_node])

for x in shortest_path_node:
    if x == -1 :
        print('INF')
    else:
        print(x)