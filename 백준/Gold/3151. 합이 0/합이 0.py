from sys import stdin

N = int(stdin.readline())
values = list(map(int, stdin.readline().split()))
values.sort()

def find_left(start, end, val):
    while start<end:
        mid = int((start+end)/2)
        if values[mid] < val:
            start=mid+1
        else:
            end=mid
    return start

count_sum = 0
for start in range(0, N-2):
    mid = start+1
    end = N-1
    while mid < end:
        sum = values[start]+values[mid]+values[end]
        if sum > 0:
            end-=1
        else:
            if sum == 0:
                left = find_left(mid+1, end, values[end])
                count_sum += end - left + 1
            mid +=1
    
print(count_sum)