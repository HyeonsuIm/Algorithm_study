from sys import stdin
from sys import setrecursionlimit

def get_longest_diameter(cnt, tree, weights, position):
    CURR_LONGEST_WEIGHT=0
    CURR_WEIGHT=0

    weight_list = []
    for child, weight in tree[position]:
        if weights[child][0] == -1:
            get_longest_diameter(cnt, tree, weights, child)
            CURR_WEIGHT = max(CURR_WEIGHT, weights[child][0] + weight)
            weight_list.append(weights[child][0] + weight)
    
    weight_list.sort(reverse=True)
    weights[position][0] = CURR_WEIGHT
    if 0 == len(weight_list):
        weights[position][1] = 0
    elif 1 == len(weight_list):
        weights[position][1] = weight_list[0]
    else:
        weights[position][1] = weight_list[0] + weight_list[1]


setrecursionlimit(1000000)
cnt = int(stdin.readline())
tree = [[] for _ in range(cnt+1)]
weights = [[-1, -1] for _ in range(cnt+1)]

for _ in range(cnt-1):
    parent, child, weight = map(int, stdin.readline().split())
    tree[parent].append([child, weight])

get_longest_diameter(cnt, tree, weights, 1)

BEST_WEIGHT=0
for _, longtest_weight in weights[1:]:
    BEST_WEIGHT = max(BEST_WEIGHT, longtest_weight)

print(BEST_WEIGHT)