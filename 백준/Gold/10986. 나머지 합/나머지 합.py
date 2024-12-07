from sys import stdin
from math import inf

N, M = map(int, stdin.readline().split())
num_list = list(map(int,stdin.readline().split()))
mod_list = [0 for _ in range(M)]
sum = 0
for num in num_list:
    sum += num
    mod_list[(sum)%M]+=1

cnt = mod_list[0]
for i in range(M):
    cnt += int((mod_list[i] * (mod_list[i]-1))/2)

print(cnt)