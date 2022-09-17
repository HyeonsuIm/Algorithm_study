from sys import stdin
from sys import setrecursionlimit

def get_pre_order(in_order_positions, in_order, in_start, in_end, post_order, post_start, post_end, result):
    if post_start > post_end:
        return

    val = post_order[post_end]
    result.append(val)
    if post_start == post_end:
        return
    
    position = in_order_positions[val]
    cnt = position - in_start
    get_pre_order(in_order_positions, in_order, in_start, in_start+cnt-1, post_order, post_start, post_start+cnt-1, result)
    cnt = in_end - position
    get_pre_order(in_order_positions, in_order, in_end-cnt+1, in_end, post_order, post_end-cnt, post_end-1, result)


setrecursionlimit(1000000)
cnt = int(stdin.readline())
in_order = list(map(int, stdin.readline().split()))
post_order = list(map(int, stdin.readline().split()))
result = []

in_order_positions = [0]*(cnt+1)
for i in range(cnt):
    in_order_positions[in_order[i]] = i

get_pre_order(in_order_positions, in_order,  0, cnt-1, post_order, 0, cnt-1, result)
print(*result, sep=" ")