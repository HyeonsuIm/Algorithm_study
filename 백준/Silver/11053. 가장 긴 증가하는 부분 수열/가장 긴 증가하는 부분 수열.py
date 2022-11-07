from sys import stdin

data_cnt = int(stdin.readline().rstrip())
datas = list(map(int, stdin.readline().split()))
dp = [0 for _ in range(data_cnt)]
for i in range(data_cnt):
    BEST_INCREASE_CNT = 0
    for j in range(i):
        if datas[j] < datas[i]:
            BEST_INCREASE_CNT = max(BEST_INCREASE_CNT, dp[j])
    dp[i] = BEST_INCREASE_CNT + 1

MAX_INCRASE_CNT = 0
for i in range(data_cnt):
    MAX_INCRASE_CNT = max(dp[i], MAX_INCRASE_CNT)

print(MAX_INCRASE_CNT)