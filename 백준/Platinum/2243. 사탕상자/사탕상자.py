from sys import stdin
from sys import setrecursionlimit
from math import ceil
from math import floor


def data_tree_operate(tree, val, cnt):
    data_min = 1
    data_max = 1048577
    index = 1
    while True:
        tree[index] += cnt
        if data_min == data_max:
            break
        data_mid = int((data_min+data_max)/2)
        if data_mid >= val:
            index = index * 2
            data_max = ceil(data_mid)
        else:
            index = index * 2 + 1
            data_min = ceil(data_mid+1)


def pop_data_tree(tree, val):
    curr_index = 1
    prev_cnt = 0
    data_min = 1
    data_max = 1048577
    while True:
        tree[curr_index]-=1
        if data_min == data_max:
            break
        data_mid = int((data_min+data_max)/2)
        if prev_cnt+tree[curr_index*2] >= val:
            curr_index = curr_index*2
            data_max = ceil(data_mid)
        else:
            prev_cnt+=tree[curr_index*2]
            curr_index = curr_index * 2 + 1
            data_min = ceil(data_mid+1)
    return data_min

            
if __name__ == "__main__":
    setrecursionlimit(1000000)
    data_tree = [0 for _ in range(2097154)]
    input_cnt = int(stdin.readline().rstrip())
    for i in range(input_cnt):
        operate, *params = map(int, stdin.readline().split())
        if operate == 1:
            print(pop_data_tree(data_tree, params[0]))
        else:
            data_tree_operate(data_tree, params[0], params[1])
            