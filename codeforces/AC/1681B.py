import sys
from typing import Counter

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    [m] = gints()
    b = list(gints())
    idx = sum(b) % n
    print(a[idx])