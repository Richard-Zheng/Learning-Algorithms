import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    if n % 2 == 1:
        print('Mike')
        continue
    m = 0
    for i in range(n):
        if a[i] < a[m]:
            m = i
    if m % 2 == 0:
        print('Joe')
    else:
        print('Mike')
