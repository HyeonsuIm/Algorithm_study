from sys import stdin

def get_best_score(data_list, data_len):
    dp = [[0,0] for _ in range(data_len)]
    for i in range(data_len):
        if i == 0:
            dp[i][0] = data_list[0][i]
            dp[i][1] = data_list[1][i]
        else:
            dp[i][0] = max(dp[i-1][1]+data_list[0][i], dp[i-1][0])
            dp[i][1] = max(dp[i-1][0]+data_list[1][i], dp[i-1][1])
    
    return max(dp[data_len-1][0], dp[data_len-1][1])


T = int(stdin.readline())
result = []
for _ in range(T):
    n = int(stdin.readline())
    data_list = [[] for _ in range(2)]
    for i in range(2):
        data_list[i] = list(map(int,stdin.readline().split()))
    result.append(get_best_score(data_list, n))

print(*result, sep='\n')