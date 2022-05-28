import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    p = list(gints())
    ans = (1<<19)-1
    for i in range(n):
        if p[i] != i:
            ans &= i
    print(ans)