from sys import stdin
from sys import setrecursionlimit
from math import log2


def add_tree_data_impl(tree, node_idx, start, end, position, val):
    if start > position or end < position:
        return

    tree[node_idx]+=val
    if start != end:
        mid = int((start+end)/2)
        add_tree_data_impl(tree, node_idx*2, start, mid, position, val)
        add_tree_data_impl(tree, node_idx*2+1, mid+1, end, position, val)
    


def add_tree_data(tree, data_max, position, val):
    add_tree_data_impl(tree, 1, 1, data_max, position, val)
    
    
def get_tree_sum_impl(tree, node_idx, start, end, from_idx, to_idx):
    if start > to_idx or end < from_idx:
        return 0
    elif start >= from_idx and end <= to_idx:
        return tree[node_idx]
    
    ret = 0
    mid = int((start+end)/2)
    ret+=get_tree_sum_impl(tree, node_idx*2, start, mid, from_idx, to_idx)
    ret+=get_tree_sum_impl(tree, node_idx*2+1, mid+1, end, from_idx, to_idx)
    return ret

    
def get_tree_sum(tree, data_max, from_idx, to_idx):
    return get_tree_sum_impl(tree, 1, 1, data_max, from_idx, to_idx)
    

if __name__ == "__main__":
    setrecursionlimit(1000000)
    number_cnt, turn_cnt = map(int,stdin.readline().split())
    numbers = list(map(int, stdin.readline().split()))

    max_number_range = 2**(int(log2(number_cnt+1))+1)
    tree = [0 for _ in range(max_number_range*2+1)]
    for i, num in enumerate(numbers):
        add_tree_data(tree, max_number_range, i+1, num)
    
    for i in range(turn_cnt):
        x, y, a, b = map(int, stdin.readline().split())
        if x > y:
            x, y = y, x
        print(get_tree_sum(tree, max_number_range, x, y))
        val_diff = b - numbers[a-1]
        numbers[a-1] = b
        add_tree_data(tree, max_number_range, a, val_diff)