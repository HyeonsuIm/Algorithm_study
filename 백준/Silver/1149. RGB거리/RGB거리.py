from sys import stdin

house_number = int(stdin.readline().rstrip())
color_cost = []
for _ in range(house_number):
    color_cost.append(list(map(int,stdin.readline().split())))

set_colors = [[0,0,0] for _ in range(house_number)]
for i in range(house_number):
    for j in range(3):
        if i == 0:
            set_colors[i][j] = color_cost[i][j]
        else:
            if j == 0:
                set_colors[i][j] = color_cost[i][j] + min(set_colors[i-1][1], set_colors[i-1][2])
            elif j == 1:
                set_colors[i][j] = color_cost[i][j] + min(set_colors[i-1][0], set_colors[i-1][2])
            else:
                set_colors[i][j] = color_cost[i][j] + min(set_colors[i-1][0], set_colors[i-1][1])

print(min(*set_colors[house_number-1]))