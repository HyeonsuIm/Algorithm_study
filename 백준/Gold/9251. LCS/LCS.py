from sys import stdin

first_str = stdin.readline().rstrip()
second_str = stdin.readline().rstrip()

max_length = max(len(first_str), len(second_str))
min_length = min(len(first_str), len(second_str))
matching_result = [[0 for _ in range(len(second_str)+1)] for _ in range(len(first_str)+1)]

for i, first_char in enumerate(first_str):
    for j, second_char in enumerate(second_str):
        if first_char == second_char:
            matching_result[i+1][j+1] = matching_result[i][j] + 1
        else:
            matching_result[i+1][j+1] = max(matching_result[i][j+1], matching_result[i+1][j])

MAX_VAL = 0
for i in range(len(first_str)+1):
    for j in range(len(second_str)+1):
        MAX_VAL = max(MAX_VAL, matching_result[i][j])

print(MAX_VAL)