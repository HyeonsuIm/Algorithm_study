from sys import stdin

def solve(data_cnt, finish_cnt, position, selected_list, selected_cnt):
    if position > data_cnt:
        return

    if selected_cnt == finish_cnt:
        for i in range(1, data_cnt+1):
            for _ in range(selected_list[i]):
                print(i, end=' ')
        print()
        return

    selected_list[position] += 1
    solve(data_cnt, finish_cnt, position, selected_list, selected_cnt+1)
    #solve(data_cnt, finish_cnt, position+1, selected_list, selected_cnt+1)
    selected_list[position] -= 1
    solve(data_cnt, finish_cnt, position+1, selected_list, selected_cnt)
    


N, M = map(int, stdin.readline().split())
selected_list = [False for _ in range(N+1)]
solve(N,M,1,selected_list, 0)