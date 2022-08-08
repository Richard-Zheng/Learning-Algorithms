import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    a,b = gints()
    pr = min(a,b)
    for i in range(pr):
        print('01', end='')
    a -= pr
    b -= pr
    for i in range(a):
        print('0', end='')
    for i in range(b):
        print('1', end='')
    print()