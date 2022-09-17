from sys import stdin


N, K = map(int, stdin.readline().split())
items = []
for _ in range(N):
    W, V = map(int, stdin.readline().split())
    if K < W or V == 0:
        continue
    items.append([W,V])

dp = [0 for _ in range(K+1)]
N = len(items)

for i in range(N):
    for j in range(K, 0 ,-1):
        if items[i][0] <= j:
            dp[j] = max(dp[j], dp[j-items[i][0]]+items[i][1])

print(dp[K])