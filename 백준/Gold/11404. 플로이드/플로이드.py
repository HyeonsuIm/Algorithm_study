from sys import stdin
from math import inf
from heapq import heappush, heappop


def make_path(city_cnt, graph, start_point, result):
    heap = []
    finish_count = 1
    heappush(heap, [0, start_point])
    while heap and finish_count != city_cnt:
        cost, point = heappop(heap)
        if result[point] == 0 and point != start_point:
            result[point] = cost
            finish_count += 1

        for next_city, move_cost in graph[point]:
            heappush(heap, [cost+move_cost, next_city])


def make_minimum_cost(city_cnt, graph, start_point):
    result = [0 for _ in range(city_cnt)]
    make_path(city_cnt, graph, start_point, result)
    return result

    


N = int(stdin.readline().rstrip())
M = int(stdin.readline().rstrip())

graph = [[inf for _ in range(N)] for _ in range(N)]
for _ in range(M):
    a, b, cost = map(int, stdin.readline().split())
    if graph[a-1][b-1] > cost:
        graph[a-1][b-1] = cost

for i in range(N):
    for j in range(N):        
        for k in range(N):
            if graph[j][i] != inf and graph[i][k] != inf:
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])


for i in range(N):
    for j in range(N):
        if i==j:
            graph[i][j] = 0
        elif graph[i][j] == inf:
            graph[i][j] = 0

for list in graph:
    print(*list, sep=' ')
