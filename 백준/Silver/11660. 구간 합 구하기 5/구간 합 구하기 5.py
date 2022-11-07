from sys import stdin
N, M = map(int,stdin.readline().split())
table = [[] for _ in range(N)]
sum_table = [[0] * N for _ in range(N)]
for x in range(N):
    table[x] = list(map(int, stdin.readline().split()))

for x in range(N):
    for y in range(N):
        if x == 0 and y == 0:
            sum_table[x][y] = table[x][y]
        elif x == 0:
            sum_table[x][y] = sum_table[x][y-1] + table[x][y]
        elif y == 0:
            sum_table[x][y] = sum_table[x-1][y] + table[x][y]
        else:
            sum_table[x][y] = sum_table[x-1][y] + sum_table[x][y-1] - sum_table[x-1][y-1] + table[x][y]


results = []
for x in range(M):
    x1,y1,x2,y2 = map(int, stdin.readline().split())
    y1 -= 1
    x2 -= 1
    x1 -= 1
    y2 -= 1

    minus_val = 0
    if y1 == 0 and x1 == 0:
        minus_val = 0
    elif y1 == 0:
        minus_val = sum_table[x1-1][y2]
    elif x1 == 0:
        minus_val = sum_table[x2][y1-1]
    else:
        minus_val = sum_table[x1-1][y2] + sum_table[x2][y1-1] - sum_table[x1-1][y1-1]
    results.append(sum_table[x2][y2] - minus_val)

print(*results, sep='\n')