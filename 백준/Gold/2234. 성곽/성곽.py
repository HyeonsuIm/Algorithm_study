from sys import stdin

next = [[0,1,4],
        [0,-1,1],
        [-1,0,2],
        [1,0,8]]
N, M = map(int,stdin.readline().split())
map_info = []
for _ in range(M):
    map_info.append(list(map(int, stdin.readline().split())))

size_map = [[-1 for _ in range(N)] for _ in range(M)]
room_cnt_list = []
for j in range(M):
    for i in range(N):
        if size_map[j][i] == -1:
            size_map[j][i] = len(room_cnt_list)
            room_cnt = 1
            queue = [[j,i]]
            while queue:
                y,x = queue.pop()
                for dy,dx,bitflag in next:
                    if (bitflag & map_info[y][x]) == 0:
                        if size_map[y+dy][x+dx] == -1:
                            size_map[y+dy][x+dx] = len(room_cnt_list)
                            room_cnt+=1
                            queue.append([y+dy,x+dx])
            room_cnt_list.append(room_cnt)

max_merged_room_cnt = 0
for y in range(M):
    for x in range(N):
        for dy, dx, bitflag in next:
            if x+dx < 0 or y+dy < 0 or x+dx >=N or y+dy >=M:
                continue
            
            if (bitflag & map_info[y][x]) != 0:
                if size_map[y][x] != size_map[y+dy][x+dx]:
                    max_merged_room_cnt = max(max_merged_room_cnt, room_cnt_list[size_map[y][x]]+room_cnt_list[size_map[y+dy][x+dx]])
            

print(len(room_cnt_list))
print(max(room_cnt_list))
print(max_merged_room_cnt)