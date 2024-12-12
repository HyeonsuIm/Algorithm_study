from sys import stdin

N = int(stdin.readline())
A = list(map(int, stdin.readline().split()))
B = list(map(int, stdin.readline().split()))
C = list(map(int, stdin.readline().split()))

is_success = True
before_score = -1
for a,b,c in zip(A,B,C):
    min_score = min(a,b,c)
    max_score = max(a,b,c)
    if before_score < min_score:
        before_score = min_score
    elif before_score < max_score:
        before_score += 1
    else:
        is_success=False
        break

if is_success:
    print("YES")
else:
    print("NO")