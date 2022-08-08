import sys
import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    if n % 2 == 1:
        print(n, *range(1, n))
    else:
        for i in range(1, n+1, 2):
            print(i+1, i, end=' ')
