from sys import stdin

luggage_compartment_cnt = int(stdin.readline().rstrip())
data_list =[]
for i in range(luggage_compartment_cnt):
    data_list.append([int(stdin.readline().rstrip()), i])

data_list_sorted = list(data_list)
data_list_sorted.sort()
is_checked = [False for _, _ in data_list]
total_cost = 0
for i, cost in enumerate(data_list_sorted):
    if is_checked[i] == True:
        continue
    
    # 제자리에 없는 요소들은 무조건 한번씩 이동해야 한며, 같은 사이클에 연결된 리스트들을 가장 작은 값을 가지고 돌려서 맞춘다.
    data_cnt = 0
    j = i
    while True:
        if is_checked[j] == True:
            break
        data_cnt+=1
        total_cost += data_list_sorted[j][0]
        is_checked[j]=True
        j = data_list_sorted[j][1]
    
    #내부의 가장 작은 값을 돌려쓰는 경우와 / 외부에 가장 작은 값을 돌려쓰는 경우 중 작은 값
    total_cost += min((data_cnt-2)* data_list_sorted[i][0], data_list_sorted[i][0] +(data_cnt+1) * data_list_sorted[0][0])
    
print(total_cost)