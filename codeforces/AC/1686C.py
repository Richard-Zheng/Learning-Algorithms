import sys
from typing import Counter

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = sorted(list(gints()))
    if n % 2 == 1:
        print('NO')
        continue
    n //= 2
    if a[n-1] == a[n]:
        c1 = Counter(a[:n])[a[n-1]]
        c2 = Counter(a[n:])[a[n]]
        if c1 + c2 + 1 > n:
            print('NO')
            continue
    print('YES')
    for i in range(n):
        print(a[i], a[n+i], end=' ')
    print('')

    