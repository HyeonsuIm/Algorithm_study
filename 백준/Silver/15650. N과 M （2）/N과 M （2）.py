from sys import stdin

def solve(data_cnt, finish_cnt, position, selected_list, selected_cnt):
    if data_cnt-position < finish_cnt - selected_cnt-1:
        return

    if selected_cnt == finish_cnt:
        for i in range(1, data_cnt+1):
            if selected_list[i] is True:
                print(i, end=' ')
        print()
        return

    selected_list[position] = True
    solve(data_cnt, finish_cnt, position+1, selected_list, selected_cnt+1)
    selected_list[position] = False
    solve(data_cnt, finish_cnt, position+1, selected_list, selected_cnt)
    


N, M = map(int, stdin.readline().split())
selected_list = [False for _ in range(N+1)]
solve(N,M,1,selected_list, 0)