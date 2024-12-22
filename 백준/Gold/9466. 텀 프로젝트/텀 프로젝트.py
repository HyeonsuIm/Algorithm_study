from sys import stdin

def dfs(graph, start, visited):
    visited[start] = True
    visited_list = [start]
    while start := graph[start]:
        if visited[start] is True:
            if start in visited_list:
                return len(visited_list[visited_list.index(start):])
            else:
                return 0
        visited[start] = True
        visited_list.append(start)

    return 0


T = int(stdin.readline())
for _ in range(T):
    n = int(stdin.readline())
    select = [0] + list(map(int, stdin.readline().split()))
    visited = [False for _ in range(n+1)]
    cnt = 0
    for i in range(1, n+1):
        if visited[i] is False:
            cnt += dfs(select,i, visited)
    print(n-cnt)