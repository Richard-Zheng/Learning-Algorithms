from cmath import inf
import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    n,m = gints()
    graph = []
    for _ in range(n):
        graph.append(input())
    minup = 6
    minleft = 6
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 'R':
                minup = min(i, minup)
                minleft = min(j, minleft)
    flag = False
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 'R':
                if i == minup and j == minleft:
                    flag = True
    print('YES' if flag else 'NO')