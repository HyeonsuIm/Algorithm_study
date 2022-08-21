from sys import stdin
from collections import deque

def Expand(cost, col, row, cols, rows, data_list, expand_list):
    if col >= 0 and col < cols and row >=0 and row < rows:
        if data_list[row][col] == 0 :
            data_list[row][col]=1
            expand_list.append([cost, col, row])


def ExpandArond(data, cols, rows, data_list, expand_list):
    Expand(data[0]+1, data[1]-1, data[2], cols, rows, data_list, expand_list)
    Expand(data[0]+1, data[1]+1, data[2], cols, rows, data_list, expand_list)
    Expand(data[0]+1, data[1], data[2]+1, cols, rows, data_list, expand_list)
    Expand(data[0]+1, data[1], data[2]-1, cols, rows, data_list, expand_list)


def GetFinishTurnCnt(cols, rows, data_list):
    expand_list=deque([])
    for row in range(rows):
        for col in range(cols):
            if 1 == data_list[row][col]:
                expand_list.append([0, col, row])
    
    last_cost = 0
    while expand_list:
        data = expand_list.popleft()
        last_cost = data[0]
        ExpandArond(data, cols,rows,data_list,expand_list)
    
    for row in range(rows):
        for col in range(cols):
            if 0 == data_list[row][col]:
                return -1
    return last_cost
    


if __name__ == '__main__':
    cols, rows = map(int, stdin.readline().split())
    data_list =[]
    for i in range(rows):
        data_list.append(list(map(int,stdin.readline().split())))
    
    print(GetFinishTurnCnt(cols,rows,data_list))