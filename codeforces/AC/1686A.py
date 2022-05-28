from math import floor
import sys

def gints(): return map(int, input().split())

[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    avg = sum(a)/n
    if avg != floor(avg) or avg not in a:
        print('NO')
    else:
        print('YES')
