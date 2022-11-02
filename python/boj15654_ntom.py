from sys import stdin

def solve(data_cnt, finish_cnt, data_list, selected_list, stack, selected_cnt):
    #if data_cnt-position < finish_cnt - selected_cnt-1:
    #    return

    if selected_cnt == finish_cnt:
        print(*stack, sep=" ")
        return

    for position in range(data_cnt):
        if selected_list[position] is False:
            selected_list[position] = True
            stack.append(data_list[position])
            solve(data_cnt, finish_cnt, data_list, selected_list, stack, selected_cnt+1)
            stack.pop()
            selected_list[position] = False
    


N, M = map(int, stdin.readline().split())
data_list = list(map(int, stdin.readline().split()))
data_list.sort()
stack = []
selected_list = [False for _ in range(N)]
solve(N,M,data_list, selected_list, stack, 0)