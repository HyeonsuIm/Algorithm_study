from sys import stdin
from math import inf

n = int(stdin.readline())
H = list(map(int,stdin.readline().split()))
A = [[val, i] for i, val in enumerate(list(map(int,stdin.readline().split())))]
A.sort()

sum = 0
for day in range(n):
    sum += A[day][0]*day + H[A[day][1]]

print(sum)