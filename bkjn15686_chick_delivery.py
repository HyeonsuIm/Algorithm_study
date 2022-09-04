from sys import stdin
from math import inf


def get_chick_dist(citys, chicks, valid_list):
    total_dist = 0
    for i,j in citys:
        min_dist = 100
        for k, valid in enumerate(valid_list):
            if valid is True:
                dist = abs(i - chicks[k][0]) + abs(j-chicks[k][1])
                if min_dist > dist:
                    min_dist = dist
        total_dist+=min_dist
    return total_dist


def get_minimum_chick_dist(citys, chicks, valid_chick_list, depth, remove_cnt):
    if remove_cnt==0:
        return get_chick_dist(citys, chicks, valid_chick_list)
    elif depth == len(chicks):
        return 1000000
    else:
        result = get_minimum_chick_dist(citys, chicks, valid_chick_list, depth+1, remove_cnt)
        valid_chick_list[depth] = False
        result = min(result, get_minimum_chick_dist(citys, chicks, valid_chick_list, depth+1, remove_cnt-1))
        valid_chick_list[depth] = True
        return result


N, M = map(int, stdin.readline().split())
city = [[int(char) for char in stdin.readline().split() ] for _ in range(N)]

citys = []
chicks = []
for i in range(N):
    for j in range(N):
        if city[i][j] == 1:
            citys.append([i,j])
        elif city[i][j] == 2:
            chicks.append([i,j])



CHICK_CNT = len(chicks)
remove_cnt = CHICK_CNT - M
valid_chick_list = [True for _ in range(CHICK_CNT)]
print(get_minimum_chick_dist(citys, chicks, valid_chick_list, 0, remove_cnt))