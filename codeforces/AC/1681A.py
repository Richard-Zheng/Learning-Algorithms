import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    gints()
    a = sorted(gints(), reverse=True)
    gints()
    b = sorted(gints(), reverse=True)
    if a[0] > b[0]:
        print('Alice\nAlice')
    elif a[0] < b[0]:
        print('Bob\nBob')
    else:
        print('Alice\nBob')