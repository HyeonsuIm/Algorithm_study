from sys import stdin

N, K, M = map(int,stdin.readline().split())
conn_lines = [[] for _ in range(N+1)]
lines = [list(map(int,stdin.readline().split())) for _ in range(M)]
for i, line in enumerate(lines):
    for station in line:
        conn_lines[station].append(i)
        
visited = [0 for _ in range(N+1)]
queue = [1]
visited[1] = 1
while queue:
    if 0 != visited[N]:
        break
    
    i = queue.pop(0)
    for line_idx in conn_lines[i]:
        for station in lines[line_idx]:
            if visited[station] == 0:
                visited[station] = visited[i]+1
                queue.append(station)
      
print(visited[N] if visited[N] != 0 else -1)