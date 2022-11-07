from sys import stdin


def diffusion(R, C, room, dust_temp):
    for i in range(R):
        for j in range(C):
            if room[i][j] > 0:
                diffusion_val = int(room[i][j] / 5)
                diffusion_cnt = 0
                if i > 0 :
                    if room[i-1][j] != -1:
                        dust_temp[i-1][j] += diffusion_val
                        diffusion_cnt+=1
                
                if i < R - 1 :
                    if room[i+1][j] != -1:
                        dust_temp[i+1][j] += diffusion_val
                        diffusion_cnt+=1
                
                if j > 0 :
                    if room[i][j-1] != -1:
                        dust_temp[i][j-1] += diffusion_val
                        diffusion_cnt+=1

                if j < C - 1 :
                    if room[i][j+1] != -1:
                        dust_temp[i][j+1] += diffusion_val
                        diffusion_cnt+=1
                
                dust_temp[i][j] -= diffusion_cnt * diffusion_val
    for i in range(R):
        for j in range(C):
            room[i][j] += dust_temp[i][j]
            dust_temp[i][j] = 0
    

def work_air_cleaner(R, C, room, air_cleaner_position):
    for i in reversed(range(1, air_cleaner_position)):
        room[i][0] = room[i-1][0]
    
    for i in range(C-1):
        room[0][i] = room[0][i+1]
    
    for i in range(air_cleaner_position):
        room[i][C-1] = room[i+1][C-1]

    for i in reversed(range(2, C)):
        room[air_cleaner_position][i] = room[air_cleaner_position][i-1]
    
    room[air_cleaner_position][1] = 0

    for i in (range(air_cleaner_position+2, R-1)):
        room[i][0] = room[i+1][0]
    
    for i in range(C-1):
        room[R-1][i] = room[R-1][i+1]
    
    for i in reversed(range(air_cleaner_position+1, R-1)):
        room[i+1][C-1] = room[i][C-1]

    for i in reversed(range(2, C)):
        room[air_cleaner_position+1][i] = room[air_cleaner_position+1][i-1]
    
    room[air_cleaner_position+1][1] = 0



def simulation(R, C, room, dust_temp, air_cleaner_position):
    diffusion(R,C, room, dust_temp)
    work_air_cleaner(R, C, room, air_cleaner_position)



R, C, T = map(int, stdin.readline().split())

room = []
for _ in range(R):
    room.append(list(map(int, stdin.readline().split())))

air_cleaner_position = 0
for i in range(R):
    if room[i][0] == -1:
        air_cleaner_position = i
        break

for _ in range(T):
    dust_temp = [[0 for _ in range(C)] for _ in range(R)]
    simulation(R, C, room, dust_temp, air_cleaner_position)

dust_cnt = 0
for i in range(R):
    for j in range(C):
        if room[i][j] > 0:
            dust_cnt += room[i][j]

print(dust_cnt)