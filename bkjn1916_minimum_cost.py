from sys import stdin
from math import inf

from heapq import heappush, heappop


def make_path(city_cnt, graph, start_point, target_point):
    heap = []
    expand_list = [inf for _ in range(city_cnt)]
    heappush(heap, [0, start_point])
    expand_list[start_point] = 0
    while heap:
        cost, point = heappop(heap)
        if point == target_point:
            return cost

        for next_city, move_cost in graph[point]:
            if expand_list[next_city] > cost+move_cost:
                expand_list[next_city] = cost+move_cost
                heappush(heap, [cost+move_cost, next_city])

    return -1


def make_minimum_cost(city_cnt, graph, start_point, target_point):
    return make_path(city_cnt, graph, start_point, target_point)
    

N = int(stdin.readline().rstrip())
M = int(stdin.readline().rstrip())

graph_temp = [[inf for _ in range(N)] for _ in range(N)]
for _ in range(M):
    a, b, cost = map(int, stdin.readline().split())
    if graph_temp[a-1][b-1] > cost:
        graph_temp[a-1][b-1] = cost

start, dest = map(int, stdin.readline().split())

graph = [[] for _ in range(N)]

for i in range(N):
    for j in range(N):
        if graph_temp[i][j] != inf:
            graph[i].append([j, graph_temp[i][j]])

print(make_minimum_cost(N, graph, start-1, dest-1))