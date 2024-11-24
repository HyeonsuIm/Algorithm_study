from sys import stdin
import math

MAX_POS = 1000001
N, K= map(int,stdin.readline().split())
cnt_list = [0 for _ in range(MAX_POS)]
for _ in range(N):
    start, end = map(int,stdin.readline().split())
    cnt_list[start] += 1
    cnt_list[end] -= 1

dp = [0 for _ in range(MAX_POS)]
sum_cnt = 0
for i in range(1, MAX_POS):
    sum_cnt += cnt_list[i-1]
    dp[i] = dp[i-1] + sum_cnt
    

start = 0
end = 1
while end!=MAX_POS:
    length_sum = dp[end] - dp[start]
    if length_sum == K:
        break
    elif length_sum > K:
        start+=1
    else:
        end+=1

if end == MAX_POS:
    print("0 0")
else:
    print(f"{start} {end}")