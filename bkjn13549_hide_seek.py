from sys import stdin
from math import log2

def to_binary(start):
    log_val = int(log2(start))
    binary = []
    for i in reversed(range(log_val+1)):
        binary.append((start >> i) & 1)

    return binary


def to_int(start):
    val = 0
    for i in start_bin:
        val*=2
        val+=i
    return val


def make_same_length(start_bin, target_bin):
    start_len = len(start_bin)
    target_len = len(target_bin)
    move_cnt=0
    current_move_cnt = 0
    for i in range(start_len):
        current_move_cnt *=2
        if start_bin[i] != target_bin[i]:
            if target_bin[i] == 1:
                current_move_cnt+=1
            else:
                current_move_cnt-=1
            start_bin[i] =target_bin[i]
    move_cnt += abs(current_move_cnt)
    while True:
        if start_len == target_len:
            break

        start_bin.append(target_bin[start_len])
        if target_bin[start_len] == 1:
            move_cnt+=1
        start_len+=1
    return move_cnt



start, target = map(int, stdin.readline().split())
start_bin = to_binary(start)
target_bin = to_binary(target)

move_cnt = 0
if start < target:
    move_cnt = make_same_length(start_bin, target_bin)
    start = to_int(start_bin)
    target = to_int(target)
print(move_cnt + abs(start-target))