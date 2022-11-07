from sys import stdin
from heapq import heappush, heappop
from math import inf

def search(graph, start, dests):
    dest_cnt = len(dests)
    results = [inf for _ in range(dest_cnt)]
    search_result = [inf for _ in range(801)]
    heap = []
    finish_cnt = 0
    heappush(heap, [0, start])
    while heap:
        cost, position = heappop(heap)
        for i in range(dest_cnt):
            if position == dests[i] and results[i] > cost:
                if results[i] == inf:
                    finish_cnt += 1
                results[i] = cost

        if finish_cnt == dest_cnt:
            break

        if search_result[position] <= cost:
            continue
        search_result[position] = cost

        for next_city, dist in graph[position]:
            heappush(heap, [cost + dist, next_city])
    return results



N, E = map(int, stdin.readline().split())
graph = [[] for _ in range(N)]
for _ in range(E):
    a, b, c = map(int, stdin.readline().split())
    graph[a-1].append([b-1, c])
    graph[b-1].append([a-1, c])

passing_nodes = list(map(int,stdin.readline().split()))
passing_nodes[0] -= 1
passing_nodes[1] -= 1
start_to_node_dists = search(graph, 0, passing_nodes)
dest_to_node_dists = search(graph, N-1, passing_nodes)
node_to_node = search(graph, passing_nodes[0], [passing_nodes[1]])

result = min(start_to_node_dists[0] + dest_to_node_dists[1],start_to_node_dists[1] + dest_to_node_dists[0]) + node_to_node[0]
result = min(result, start_to_node_dists[0] + dest_to_node_dists[0] + node_to_node[0] * 2)
result = min(result, start_to_node_dists[1] + dest_to_node_dists[1] + node_to_node[0] * 2)

if result == inf:
    print(-1)
else:
    print(result)