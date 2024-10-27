from sys import stdin
import math

val = int(stdin.readline())
dp = [0 for _ in range(val+1)]
for i in range(1,val+1):
    dp[i] = i
    if int(math.sqrt(i)) > 1:
        dp[i] = min(dp[i], min([dp[i-j*j]+1 for j in range(1,int(math.sqrt(i)+1))]))
    
print(dp[val])