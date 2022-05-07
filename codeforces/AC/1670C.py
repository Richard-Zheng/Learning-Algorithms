from itertools import permutations
import sys
from collections import OrderedDict


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    b = list(gints())
    c = set(filter(lambda x: x != 0, gints()))
    c.update((a[i] for i in range(n) if a[i] == b[i]))
    ba = dict(zip(b, a))
    nexta = [-1]+[i for _, i in sorted(ba.items())]
    vis = set()
    cnt = 0
    for i in range(1, n+1):
        if i in vis:
            continue
        x = i
        flag = True
        while x not in vis:
            if x in c:
                flag = False
            vis.add(x)
            x = nexta[x]
        if flag:
            cnt += 1

    print(pow(2, cnt, 1000000007))
