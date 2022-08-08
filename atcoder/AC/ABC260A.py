import sys
from typing import Counter


def gints(): return map(int, sys.stdin.readline().strip().split())


s = input()
c = Counter(s)
flag = False
for i in c:
    if c[i] == 1:
        print(i)
        flag=True
        break
if not flag:
    print(-1)