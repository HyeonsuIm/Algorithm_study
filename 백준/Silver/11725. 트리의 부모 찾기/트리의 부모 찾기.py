from sys import stdin
from sys import setrecursionlimit

def find_parents(graph, node, parents, visited):
    visited[node] = True
    for next_node in graph[node]:
        if visited[next_node] is True:
            continue
        
        parents[next_node]=node+1
        find_parents(graph, next_node, parents, visited)

setrecursionlimit(1000000)
node_cnt = int(stdin.readline().rstrip())
graph = [[] for _ in range(node_cnt)]
parents = [-1 for _ in range(node_cnt)]
visited = [False for _ in range(node_cnt)]
for _ in range(node_cnt-1):
    node1, node2 = map(int, stdin.readline().split())
    graph[node1-1].append(node2-1)
    graph[node2-1].append(node1-1)

find_parents(graph, 0, parents, visited)
print(*parents[1:], sep="\n")