from sys import stdin

data_cnt = int(stdin.readline().rstrip())
data_list =[]
for i in range(data_cnt):
    data_list.append(list(map(int,stdin.readline().split())))

rate_list = []
for i, value1 in enumerate(data_list):
    rate=1
    for j, value2 in enumerate(data_list):
        if i != j:
            if value1[0] < value2[0] and value1[1] < value2[1]:
                rate+=1
    rate_list.append(rate)

print(*rate_list, sep=" ")