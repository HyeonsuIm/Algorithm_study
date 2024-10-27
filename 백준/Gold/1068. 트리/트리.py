from sys import stdin

nodeCnt = int(stdin.readline())
parents = list(map(int, stdin.readline().split()))
remove_node = int(stdin.readline())

childs = [[] for _ in parents]
for nodeIdx, parentNode in enumerate(parents):
    if parentNode != -1:
        childs[parentNode].append(nodeIdx)

master = parents.index(-1)
leaf_node_cnt = 0
if master != remove_node:
    childs[parents[remove_node]].remove(remove_node)
    check_stack=[master]
    while check_stack:
        check_node = check_stack.pop()
        is_leaf = True
        for child in childs[check_node]:
            is_leaf = False
            check_stack.append(child)
        
        leaf_node_cnt += 1 if is_leaf else 0

print(leaf_node_cnt)