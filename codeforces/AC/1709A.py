import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [x] = gints()
    l = list(gints())
    if l[x-1] != 0 and l[l[x-1]-1] != 0:
        print('YES')
    else:
        print('NO')