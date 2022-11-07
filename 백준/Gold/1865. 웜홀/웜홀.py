from sys import stdin
from math import inf


def bf(start):
    node_costs = [10001 for _ in range(N+1)]
    node_costs[1] = 0
    for j in range(N):
        for S, E, T in edges:
            if node_costs[S] + T < node_costs[E]:
                node_costs[E] = node_costs[S]+T
                if j == N-1:
                    return True
    return False

tc = int(stdin.readline())
for _ in range(tc):
    N, M, W = map(int, stdin.readline().split())
    edges = []
    for _ in range(M):
        S, E, T = map(int, stdin.readline().split())
        edges.append([S, E,T])
        edges.append([E, S,T])
    
    for _ in range(W):
        S, E, T = map(int, stdin.readline().split())
        edges.append([S, E,-T])
    
    if bf(1) is True:
        print('YES')
    else:
        print('NO')