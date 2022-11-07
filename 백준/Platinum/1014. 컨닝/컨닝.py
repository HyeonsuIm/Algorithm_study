from sys import stdin
from sys import setrecursionlimit
from math import log2

def make_sit_cases_dfs(sit_cases, index, w, sit_array):
    if index == w:
        return sit_cases.append(list(sit_array))
        
    sit_array[index]=0
    make_sit_cases_dfs(sit_cases, index+1, w, sit_array)
    
    if index == 0 or sit_array[index-1] == 0:
        sit_array[index]=1
        make_sit_cases_dfs(sit_cases, index+1, w, sit_array)
        
        
def get_best_sit_position(bit_mask, sit_cases, board, curr_h, max_w, max_h, prev_bits):
    if curr_h == max_h:
        return 0
    
    if bit_mask[curr_h][prev_bits] != -1:
        return bit_mask[curr_h][prev_bits]
    
    result = 0
    for sit_array in sit_cases:
        bits = 0
        count = 0
        for i in range(max_w):
            if sit_array[i] == 0:
                continue
                
            if board[curr_h][i] == 'x':
                continue
            
            if i > 0 :
                if prev_bits & (1 << (i-1)):
                    continue
            
            if i < max_w-1:
                if prev_bits & (1 << (i+1)):
                    continue
            
            count+=1
            bits |= 1 << i
        
        result = max(result, get_best_sit_position(bit_mask, sit_cases, board, curr_h+1, max_w, max_h, bits)+count)
    bit_mask[curr_h][prev_bits]=result
    return result


if __name__ == "__main__":
    setrecursionlimit(1000000)
    case_cnt = int(stdin.readline().rstrip())
    for _ in range(case_cnt):
        h, w = map(int, stdin.readline().split())
        sit_array = [0 for _ in range(w)]
        sit_cases = []
        make_sit_cases_dfs(sit_cases, 0, w, sit_array)
        
        board = []
        for i in range(h):
            board.append(list(stdin.readline().rstrip()))
            
        bit_mask = [[-1 for _ in range(2**w)]for _ in range(h)]
        print(get_best_sit_position(bit_mask, sit_cases, board, 0, w, h, 0))
        