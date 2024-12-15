from sys import stdin

R = int(stdin.readline())
N = int(stdin.readline())
Ri = list(map(int, stdin.readline().split()))

R_min = R
R_max = R
same_rank_cnt=0

for rank in Ri:
    if rank <= R_max:
        R_max+=1
    
    if rank == R_min:
        same_rank_cnt+=1
    elif rank < R_min:
        R_min+=1
    else:
        if rank <= R_min + same_rank_cnt:
            same_rank_cnt = same_rank_cnt - (rank - R_min) + 1
            R_min = rank

print(f"{R_min} {R_max}")