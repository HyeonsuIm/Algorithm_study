from sys import stdin

def dfs(graph, visited, root):
    if visited[root] is False:
        visited[root] = True
        for next in graph[root]:
            dfs(graph, visited, next)
    

N, M = map(int, stdin.readline().split())
graph = [[] for _ in range(N)]
in_bound = [0 for _ in range(N)]
for _ in range(M):
    fr, to = map(str, stdin.readline().split())
    fr = ord(fr) - ord('A')
    to = ord(to) - ord('A')
    graph[fr].append(to)
    in_bound[to] += 1
    
_, *people = map(str, stdin.readline().split())
for member in people:
    graph[ord(member) - ord('A')].clear()

boss_list = []
for i, cnt in enumerate(in_bound):
    if cnt == 0:
        boss_list.append(i)

visited = [False for _ in range(N)]
for root in boss_list:
    dfs(graph, visited, root)

for member in people:
    visited[ord(member) - ord('A')] = False
    
for root in boss_list:
    visited[root] = False

visit_cnt = 0
for visit in visited:
    if visit:
        visit_cnt+=1

print(visit_cnt)