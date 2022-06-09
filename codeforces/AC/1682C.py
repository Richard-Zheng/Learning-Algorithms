from collections import Counter
from functools import reduce
from math import floor
import sys

def gints(): return map(int, input().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    a = list(gints())
    c = Counter(a).most_common()
    cnt = 0
    for i in c:
        if i[1] == 1:
            cnt += 1
        else:
            cnt += 2
    print(1 + (cnt-1)//2)