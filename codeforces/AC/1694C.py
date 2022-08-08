import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    pre = [a[i] for i in range(n)]
    su = 0
    flag = True
    haszero = False
    for i in range(n):
        su += a[i]
        if i > 0:
            pre[i] += pre[i-1]
        if pre[i] < 0:
            flag = False
        if pre[i] == 0:
            if haszero:
                if a[i] != 0:
                    flag = False
            else:
                haszero = True
    if su != 0 or a[n-1] > 0:
        flag = False
    print('Yes' if flag else 'No')
