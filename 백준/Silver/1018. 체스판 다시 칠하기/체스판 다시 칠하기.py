from sys import stdin

cols, rows = map(int, stdin.readline().split())
chess_board=[]
for i in range(cols):
    chess_board.append([char for char in stdin.readline().rstrip()])

change_count = 0
wrong_color_board=[[0]*rows for _ in range(cols)]
for row in range(cols):
    for col in range(rows):
        correct_color = 'W' if (col+row)%2 == 0 else 'B'
        change_count=0
        if correct_color != chess_board[row][col]:
            change_count += 1
        
        if row > 0 :
             wrong_color_board[row][col] += wrong_color_board[row-1][col]
        
        if col > 0 :
            wrong_color_board[row][col] += wrong_color_board[row][col-1]
        
        if row > 0 and col > 0:
            wrong_color_board[row][col] -= wrong_color_board[row-1][col-1]
            
        wrong_color_board[row][col] += change_count

min_count = 8*8
for col in range(rows-7):
    for row in range(cols-7):
        wrong_color_count = wrong_color_board[row+7][col+7]
        if row > 0:
            wrong_color_count -= wrong_color_board[row-1][col+7]
        
        if col > 0 :
            wrong_color_count -= wrong_color_board[row+7][col-1]
        
        if row > 0 and col > 0:
            wrong_color_count += wrong_color_board[row-1][col-1]
            
        wrong_color_count_in_board = wrong_color_count if wrong_color_count < 32 else 64 - wrong_color_count
        if wrong_color_count_in_board < min_count:
            min_count = wrong_color_count_in_board

print(min_count)