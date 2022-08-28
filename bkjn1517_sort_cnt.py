"""bkjn 1517 problem solve"""
from sys import stdin
from math import log2
from math import ceil


def read_inputs():
    """read inputs"""
    input_cnt = int(stdin.readline())
    input_list = map(int, stdin.readline().split())
    return input_cnt, input_list


def insert_segment_tree(segment_tree, max_data_cnt, idx):
    """insert data into segment tree"""
    start_idx = 0
    end_idx = max_data_cnt - 1
    mid_idx = int((start_idx + end_idx)/2)
    curr_node_idx = 1
    while True:
        segment_tree[curr_node_idx]+=1
        if start_idx == end_idx:
            break

        if start_idx <= idx <= mid_idx:
            curr_node_idx *= 2
            end_idx = mid_idx
        else:
            curr_node_idx = curr_node_idx * 2 + 1
            start_idx = mid_idx+1
        mid_idx = int((start_idx+end_idx)/2)


def get_small_right_cnt_impl(segment_tree, start_idx, end_idx,\
     node_idx, node_start_idx, node_end_idx):
    """implement getting small values on right side from idx"""
    if node_start_idx > end_idx or node_end_idx < start_idx:
        return 0

    if start_idx <= node_start_idx and end_idx >= node_end_idx:
        return segment_tree[node_idx]

    mid_idx = int((node_start_idx + node_end_idx) / 2)
    result = get_small_right_cnt_impl(\
        segment_tree, start_idx, end_idx, node_idx*2, node_start_idx, mid_idx)
    result += get_small_right_cnt_impl(\
        segment_tree, start_idx, end_idx, node_idx*2+1, mid_idx+1, node_end_idx)
    return result


def get_small_right_cnt(segment_tree, start_idx, end_idx):
    """getting small values on right side from idx"""
    if end_idx < start_idx:
        return 0

    return get_small_right_cnt_impl(segment_tree, start_idx, end_idx, 1, 0, end_idx)



if __name__ == "__main__":
    data_cnt, data_list = read_inputs()
    data_list_sorted = [[data, i] for i, data in enumerate(data_list)]
    data_list_sorted.sort()

    max_tree_cnt = pow(2, ceil(log2(data_cnt))) * 2 + 1
    segment_tree_base = [0 for _ in range(max_tree_cnt)]
    SWAP_CNT = 0
    for data, index in data_list_sorted:
        SWAP_CNT += get_small_right_cnt(segment_tree_base, index+1, data_cnt-1)
        insert_segment_tree(segment_tree_base, data_cnt, index)

    print(SWAP_CNT)
