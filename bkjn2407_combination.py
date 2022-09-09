from sys import stdin

datas = [[-1 for _ in range(101)] for _ in range(101)]

def ncr(n, m):
    if m == 0 or n == m:
        return 1
    if datas[n][m] != -1:
        return datas[n][m]
    else:
        result = ncr(n-1, m) + ncr(n-1, m-1)
        datas[n][m] = result
        return result

n, m = map(int,stdin.readline().split())
print(ncr(n,m))