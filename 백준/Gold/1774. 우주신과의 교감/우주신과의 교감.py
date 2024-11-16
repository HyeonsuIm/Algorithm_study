from sys import stdin
import math

def get_dist(coord1, coord2):
    xdiff = abs(coord1[0]-coord2[0])
    ydiff = abs(coord1[1]-coord2[1])
    return math.sqrt(xdiff*xdiff + ydiff*ydiff)

def find_parent(idx):
    if parents[idx] == idx:
        return idx
    else:
        parents[idx] = find_parent(parents[idx])
        return parents[idx]

def merge_node(idx1, idx2):
    idx1 = find_parent(idx1)
    idx2 = find_parent(idx2)
    
    if idx1 != idx2: 
        parents[idx1] = idx2

N, M = map(int,stdin.readline().split())

parents = [i for i in range(N)]
coords = []
for _ in range(N):
    coords.append(list(map(int, stdin.readline().split())))

for _ in range(M):
    fr, to = map(int, stdin.readline().split())
    merge_node(fr-1,to-1)

pq = []
for i in range(N-1):
    for j in range(i+1, N):
        pq.append([get_dist(coords[i], coords[j]), i, j])

pq.sort()

cost = 0
selCnt = 0
for data in pq:
    fr = data[1]
    to = data[2]
    if find_parent(fr) != find_parent(to):
        cost += data[0]
        selCnt += 1
        merge_node(fr, to)

print(f'{cost:.2f}')