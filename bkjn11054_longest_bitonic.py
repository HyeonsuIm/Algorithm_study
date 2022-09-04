from sys import stdin

num_cnt = int(stdin.readline().rstrip())
numbers = list(map(int, stdin.readline().split()))

result = [[[0,0,0] for _ in range(num_cnt+1)] for _ in range(num_cnt+1)]
for i in range(num_cnt):
    for j in range(num_cnt):
        if result[i-1][j-1][2] == 0:
            numbers[i]
        else:



for x in result:
    if MAX_CNT < x:
        MAX_CNT = x

print(x)
        