import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a=sorted(gints())
    hassamevalue = False
    zerocnt = 0
    for i in range(n):
        if i > 0 and a[i-1] == a[i]:
            hassamevalue = True
        if a[i] == 0:
            zerocnt += 1
    if zerocnt > 0:
        print(n-zerocnt)
    elif hassamevalue:
        print(n)
    else:
        print(n+1)
