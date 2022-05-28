import sys
from typing import Counter

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = [0] + list(gints())
    b = [0] + list(gints())
    ans = []
    for i in range(1, n+1):
        mi = min(range(i, n+1), key=lambda idx: a[idx])
        if i == mi:
            continue
        a[i], a[mi] = a[mi], a[i]
        b[i], b[mi] = b[mi], b[i]
        ans.append((i, mi))
    for i in range(1,n+1):
        mi = min(range(i, n+1), key=lambda idx: b[idx])
        if i == mi:
            continue
        a[i], a[mi] = a[mi], a[i]
        b[i], b[mi] = b[mi], b[i]
        ans.append((i, mi))
    flag = True
    for i in range(1, n+1):
        if a[i-1] > a[i]:
            flag = False
    if flag:
        print(len(ans))
        for i in ans:
            print(*i)
    else:
        print(-1)


        
