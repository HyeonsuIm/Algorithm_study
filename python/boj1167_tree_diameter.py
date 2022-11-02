from sys import stdin
from math import inf


def dfs(graph, cost_list, position, cost):
    if cost_list[position] < cost:
        return [0,0]
    
    cost_list[position] = cost

    max_cost = cost
    max_cost_position = position

    for next_position, weight in graph[position]:
        new_cost, new_cost_position = dfs(graph, cost_list, next_position, cost+weight)
        if max_cost < new_cost:
            max_cost = new_cost
            max_cost_position = new_cost_position
    
    return [max_cost, max_cost_position]


cnt = int(stdin.readline())
graph = [[] for _ in range(cnt+1)]
for _ in range(cnt):
    node_num, *args = map(int, stdin.readline().split())
    node_list = args[0::2]
    weight_list = args[1::2]
    for i, node_id in enumerate(node_list):
        if node_id != -1:
            graph[node_num].append([node_id, weight_list[i]])


cost_list = [inf for _ in range(cnt+1)]
_, max_cost_position = dfs(graph, cost_list, 1, 0)

cost_list = [inf for _ in range(cnt+1)]
max_cost, _ = dfs(graph, cost_list, max_cost_position, 0)

print(max_cost)