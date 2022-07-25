from sys import stdin

def GetMinSigmaval(move_cnt):
    sum=0
    last_cnt=0
    for i in range(1, move_cnt+1):
        sum+=i
        if sum >= move_cnt:
            last_cnt=i-1
            sum-=i
            break
            
    return (last_cnt, sum)

problem_count = int(stdin.readline())
for _ in range(problem_count):
    start_index, end_index = map(int,stdin.readline().split())
    num_of_move = end_index-start_index
    count, sum = GetMinSigmaval(int((num_of_move+1)/2))
    if num_of_move - 2 * sum > count+1:
        print(2*count+2)
    else:
        print(2*count+1)