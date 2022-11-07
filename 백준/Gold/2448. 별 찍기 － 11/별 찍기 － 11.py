from sys import stdin

def divide_cases(draw_map, base_x, base_y, size):
    if size != 3:
        next_size = size//2
        divide_cases(draw_map, base_x, base_y, next_size)
        divide_cases(draw_map, base_x-next_size, base_y+next_size, next_size)
        divide_cases(draw_map, base_x+next_size, base_y+next_size, next_size)
    else:
        draw_map[base_y][base_x]='*'
        draw_map[base_y+1][base_x-1]=draw_map[base_y+1][base_x+1]='*'
        for k in range(-2,3):
            draw_map[base_y+2][base_x-k]='*'



line_cnt = int(stdin.readline().rstrip())
draw_area = [[' ' for _ in range(line_cnt*2)] for _ in range(line_cnt)]

divide_cases(draw_area, line_cnt-1, 0, line_cnt)

result = ''
for i in range(line_cnt):
    print(*draw_area[i], sep='')
    # for j in range(line_cnt * 2):
    #     result += draw_area[i][j]
    # if i != line_cnt-1:
    #     result += '\n'

# print(result)