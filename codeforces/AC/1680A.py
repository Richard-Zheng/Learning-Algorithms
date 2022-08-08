import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    l1,r1,l2,r2 = gints()
    if l1 > l2:
        l1, r1, l2, r2 = l2, r2, l1, r1
    if l2 <= r1:
        print(l2)
    else:
        print(l1+l2)