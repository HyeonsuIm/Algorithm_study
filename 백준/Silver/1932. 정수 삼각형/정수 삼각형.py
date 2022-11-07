from sys import stdin

depth = int(stdin.readline().rstrip())
datas = [[] for _ in range(depth)]
dp = [[0 for _ in range(depth)] for _ in range(depth)]
for i in range(depth):
    datas[i] = list(map(int, stdin.readline().split()))
    if i == 0:
        dp[i][0] = datas[i][0]
    else:
        for j in range(i+1):
            if j == 0 :
                dp[i][j] = datas[i][j] + dp[i-1][j]
            elif j == i:
                dp[i][j] = datas[i][j] + dp[i-1][j-1]
            else:
                dp[i][j] = datas[i][j] + max(dp[i-1][j], dp[i-1][j-1])

MAX = 0
for i in range(depth):
    MAX = max(MAX, dp[depth-1][i])
print(MAX)