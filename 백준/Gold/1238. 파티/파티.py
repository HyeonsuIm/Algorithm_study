"""bkjn1238"""
from sys import stdin
from math import inf
from heapq import heappush, heappop

# 목적지 -> 출발지 구하기.
# 역방향 : 모일때, 정방향 : 흩어질 때
def get_shortest_paths(member_cnt, graph, target):
    """get_shortest_paths"""
    results = [inf for _ in range(member_cnt)]
    finish_cnt = 0
    heap = []
    heappush(heap, [0, target])
    results[target] = 0
    while heap:
        cost, city = heappop(heap)
        if results[city] == inf:
            finish_cnt+=1
        
        if results[city] > cost:
            results[city] = cost

        if finish_cnt == member_cnt:
            break
        for next_city, move_cost in graph[city]:
            next_cost = cost + move_cost
            if results[next_city] > next_cost:
                heappush(heap, [next_cost, next_city])
        if finish_cnt == member_cnt:
            break

    return results


N, M, X = map(int, stdin.readline().split())
graph = [[] for _ in range(N)]
graph_reverse = [[] for _ in range(N)]
for _ in range(M):
    A, B, T = map(int, stdin.readline().split())
    graph[A-1].append([B-1,T])
    graph_reverse[B-1].append([A-1,T])

result_forward = get_shortest_paths(N, graph, X-1)
result_backward = get_shortest_paths(N, graph_reverse, X-1)

MAX = 0
for i in range(N):
    MAX = max(MAX, result_forward[i] + result_backward[i])

print(MAX)