import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    hasdec=False
    flag = True
    for i in range(1,n):
        if a[i-1] < a[i] and hasdec:
            flag=False
        elif a[i-1] > a[i] and not hasdec:
            hasdec=True
    print('YES' if flag else 'NO')