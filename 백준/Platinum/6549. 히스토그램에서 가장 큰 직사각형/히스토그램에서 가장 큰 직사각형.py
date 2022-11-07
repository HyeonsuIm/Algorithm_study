from sys import stdin

while True:
    cnt, *params = map(int,stdin.readline().split())
    if cnt == 0:
        break
    else:
        result = 0
        data_list = params
        data_list.append(0)
        stack = []
        for i in range(len(data_list)):
            if stack:
                last_element_idx = -1
                is_finish = False
                
                if stack:
                    while data_list[i] < data_list[stack[-1][0]]:
                        last_element_idx, last_element_height = stack.pop()
                        result = max(result,(i - last_element_idx)*last_element_height)
                        if not stack:
                            break
                if last_element_idx != -1:
                    stack.append([last_element_idx, data_list[i]])
            stack.append([i, data_list[i]])
        print(result)