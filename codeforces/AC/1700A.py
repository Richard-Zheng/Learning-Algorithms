import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    n,m = gints()
    if n == 1:
        print((1+m)*m//2)
    else:
        print((1+m-1)*(m-1)//2+(m+n*m)*n//2)