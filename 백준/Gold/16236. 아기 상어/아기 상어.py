"""bkjn 16236 problem solve"""
from sys import stdin
from queue import PriorityQueue


def check_eat_path(move_map, map_size, pos_x, pos_y, shark_size):
    """Get minimum length path"""
    queue = PriorityQueue()
    queue.put([0, pos_y,pos_x])
    search_map = [[0 for _ in range(len(move_map))] for _ in range(len(move_map))]
    search_map[pos_y][pos_x]= 1

    while not queue.empty():
        dist, curr_pos_y, curr_pos_x = queue.get()
        if curr_pos_x < 0 or \
            curr_pos_y < 0 or \
            curr_pos_x >= map_size or\
            curr_pos_y >= map_size:
            continue

        if dist != 0:
            if search_map[curr_pos_y][curr_pos_x] in [1,9]:
                continue
            elif move_map[curr_pos_y][curr_pos_x] > shark_size:
                continue
            elif 0 < move_map[curr_pos_y][curr_pos_x] < shark_size:
                return curr_pos_y, curr_pos_x, dist

        search_map[curr_pos_y][curr_pos_x] = 1
        queue.put([dist+1, curr_pos_y-1, curr_pos_x])
        queue.put([dist+1, curr_pos_y, curr_pos_x-1])
        queue.put([dist+1, curr_pos_y, curr_pos_x+1])
        queue.put([dist+1, curr_pos_y+1, curr_pos_x])
    return -1, -1, 0


if __name__ == "__main__":
    area_size = int(stdin.readline().rstrip())
    area_map = [[int(str) for str in stdin.readline().split()] for _ in range(area_size)]
    START_X = 0
    START_Y=0
    SHARK_SIZE=2
    EAT_CNT = 0
    EAT_TIME = 0
    for i in range(area_size):
        for j in range(area_size):
            if area_map[j][i] == 9:
                START_Y = j
                START_X = i
                break

    while True:
        EAT_Y, EAT_X, DIST = check_eat_path(area_map, area_size, START_X, START_Y, SHARK_SIZE)
        if DIST == 0:
            break
        area_map[START_Y][START_X]=0
        area_map[EAT_Y][EAT_X]=9
        EAT_TIME += DIST
        EAT_CNT += 1

        if EAT_CNT == SHARK_SIZE:
            SHARK_SIZE += 1
            EAT_CNT = 0
        START_X, START_Y = EAT_X, EAT_Y

    print(EAT_TIME)
