from sys import stdin

def big_multiply(val, cnt, divide):
    if cnt == 1:
        return val % divide
    else:
        result = big_multiply(val, cnt // 2, divide)
        if cnt % 2 == 0:
            return (result * result)%divide
        else:
            return (result * result * val) %divide


A, B, C = map(int,stdin.readline().split())

print(big_multiply(A,B,C))