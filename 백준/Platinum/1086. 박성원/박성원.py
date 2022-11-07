from sys import stdin
from sys import setrecursionlimit
from math import gcd

global val_len_list
global multiple_val
global divide_val
global group_list
global is_used_arr
global total_group_cnt
global bit_mask_max


def GetInputs():
    global val_len_list
    global divide_val
    global group_list
    global total_group_cnt
    
    total_group_cnt = int(stdin.readline().rstrip())
    group_list=[0 for _ in range(total_group_cnt)]
    val_len_list = [0 for _ in range(total_group_cnt)]
    for i in range(total_group_cnt):
        group_list[i] = int(stdin.readline().rstrip())
        val_len_list[i] = len(str(group_list[i]))
    divide_val = int(stdin.readline().rstrip())
    for i in range(total_group_cnt):
        group_list[i] %= divide_val


def CheckSuccessCnt(used_bit_mask, curr_val):
    global val_len_list
    global multiple_val
    global divide_val
    global group_list
    global is_used_arr
    global bit_mask_max
    
    if used_bit_mask == bit_mask_max:
        if 0 == curr_val % divide_val:
            return 1
        else:
            return 0
    else:
        success_cnt = is_used_arr[used_bit_mask][curr_val]
        if success_cnt == -1:
            success_cnt = 0
            for i, val in enumerate(group_list):
                if used_bit_mask & (1 << i):
                    continue
                val_temp = (curr_val * (multiple_val[val_len_list[i]]) + val) % divide_val
                success_cnt += CheckSuccessCnt(used_bit_mask | (1 << i), val_temp)
            is_used_arr[used_bit_mask][curr_val] = success_cnt
        return success_cnt


def GetSuccessRate():
    global group_list
    global divide_val
    global is_used_arr
    
    is_used_arr = [[-1 for _ in range(divide_val)] for _ in range(1 << total_group_cnt)]
    
    total_case = 1
    for i in range(len(group_list)):
        total_case *= i+1
    
    global multiple_val
    multiple_val = [0 for _ in range(55)]
    multiple_val[0] = 1
    for i in range(1, 55):
        multiple_val[i] = (multiple_val[i-1]*10)%divide_val
        
    global bit_mask_max
    bit_mask_max = (1 << total_group_cnt) -1
    success_cnt = CheckSuccessCnt(0, 0)
    return success_cnt, total_case
        


if __name__ == "__main__":
    #setrecursionlimit(1000000)
    GetInputs()
    success_cnt, total_case = GetSuccessRate()
    div = gcd(success_cnt, total_case)
    print(f"{int(success_cnt / div)}/{int(total_case / div)}")