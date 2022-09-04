from sys import stdin

data_cnt = int(stdin.readline().rstrip())
datas = list(map(int, stdin.readline().split()))
dp_front = [0 for _ in range(data_cnt)]
dp_rear = [0 for _ in range(data_cnt)]
for i in range(data_cnt):
    BEST_INCREASE_CNT = 0
    for j in range(i):
        if datas[j] < datas[i]:
            BEST_INCREASE_CNT = max(BEST_INCREASE_CNT, dp_front[j])
    dp_front[i] = BEST_INCREASE_CNT + 1

for i in reversed(range(data_cnt)):
    BEST_DECREASE_CNT = 0
    for j in range(i+1, data_cnt):
        if datas[j] < datas[i]:
            BEST_DECREASE_CNT = max(BEST_DECREASE_CNT, dp_rear[j])
    dp_rear[i] = BEST_DECREASE_CNT + 1

MAX_BITONIC_SUBSEQUENCE = 0
for i in range(data_cnt):
    MAX_BITONIC_SUBSEQUENCE = max(dp_front[i]+dp_rear[i]-1, MAX_BITONIC_SUBSEQUENCE)

print(MAX_BITONIC_SUBSEQUENCE)