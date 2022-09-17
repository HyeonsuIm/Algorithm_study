from sys import stdin

def travel(type, node_info, node_position):
    result = ''
    if node_position == -1:
        return result
    if 1 == type:
        result += chr(node_position+ord('A'))
    
    result += travel(type, node_info, node_info[node_position][0])
    if 2 == type:
        result += chr(node_position+ord('A'))
    result += travel(type, node_info, node_info[node_position][1])

    if 3 == type:
        result += chr(node_position+ord('A'))
    return result
    


node_cnt = int(stdin.readline().rstrip())
node_info = [[-1,-1] for _ in range(26)]
for _ in range(node_cnt):
    node, left, right = stdin.readline().split()
    node_position = ord(node)-ord('A')
    if left == '.':
        node_info[node_position][0] = -1
    else:
        node_info[node_position][0] = ord(left)-ord('A')
    
    if right == '.':
        node_info[node_position][1] = -1
    else:
        node_info[node_position][1] = ord(right) - ord('A')

print(travel(1, node_info, 0))
print(travel(2, node_info, 0))
print(travel(3, node_info, 0))