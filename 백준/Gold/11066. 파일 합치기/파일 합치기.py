from sys import stdin
from math import inf

test_cnt = int(stdin.readline().rstrip())
cost_list = []
for _ in range(test_cnt):
    data_cnt = int(stdin.readline().rstrip())
    part_best_cost = [[inf for _ in range(data_cnt)] for _ in range(data_cnt)]
    data_list = list(map(int, stdin.readline().split()))
    sum_list = [0 for _ in range(data_cnt)]
    for part_cnt in range(1, data_cnt+1):
        for start_idx in range(data_cnt-part_cnt+1):
            if part_cnt == 1:
                part_best_cost[start_idx][start_idx] = 0
                if start_idx == 0:
                    sum_list[start_idx] = data_list[start_idx]
                else:
                    sum_list[start_idx] = data_list[start_idx] + sum_list[start_idx-1]
            else:
                last_idx = start_idx + part_cnt - 1
                SUM_VAL = 0
                if start_idx == 0 :
                    SUM_VAL = sum_list[last_idx]
                else:
                    SUM_VAL = sum_list[last_idx]-sum_list[start_idx-1]
                for middle_idx in range(start_idx,last_idx):
                    part_best_cost[start_idx][last_idx] = min(part_best_cost[start_idx][last_idx], part_best_cost[start_idx][middle_idx] + part_best_cost[middle_idx+1][last_idx]+SUM_VAL)

    cost_list.append(part_best_cost[0][data_cnt-1])


print(*cost_list, sep='\n')
