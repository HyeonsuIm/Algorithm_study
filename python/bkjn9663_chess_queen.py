from sys import stdin

RESULT = 0

def check_queen(queen_positions, visited, curr_depth, i):
    if visited[i] is True:
        return False
    for depth in range(curr_depth):
        if (curr_depth-depth) == abs(queen_positions[depth] - i):
            return False
    return True



def get_all_cases_impl(queen_positions, visited, size, depth):
    global RESULT
    if size <= depth:
        RESULT += 1
        return

    for i in range(size):
        if check_queen(queen_positions, visited, depth, i) is True:
            visited[i] = True
            queen_positions[depth] = i
            get_all_cases_impl(queen_positions, visited, size, depth+1)
            visited[i] = False


def get_all_cases(size):
    visited = [False for _ in range(size)]
    set_queens = [False for _ in range(size)]
    get_all_cases_impl(set_queens, visited, size, 0)


N = int(stdin.readline())
get_all_cases(N)
print(RESULT)
