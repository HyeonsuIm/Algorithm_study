from sys import stdin

def solve(data_list, data_cnt, finish_cnt, position, selected_list, selected_cnt):
    if position >= data_cnt:
        return

    if selected_cnt == finish_cnt:
        for i in range(data_cnt):
            for _ in range(selected_list[i]):
                print(data_list[i], end=' ')
        print()
        return

    selected_list[position] += 1
    solve(data_list, data_cnt, finish_cnt, position, selected_list, selected_cnt+1)
    selected_list[position] -= 1
    solve(data_list, data_cnt, finish_cnt, position+1, selected_list, selected_cnt)
    


N, M = map(int, stdin.readline().split())
data_list = list(map(int,stdin.readline().split()))
data_list.sort()
selected_list = [0 for _ in range(N)]
solve(data_list, N,M,0,selected_list, 0)