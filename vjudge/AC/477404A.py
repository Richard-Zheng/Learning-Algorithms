import bisect
import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())


heights = list(get_ints())

a = []
for h in heights:
    l = bisect.bisect_left(a, h)
    if l != len(a):
        a[l] = h
    else:
        a.append(h)
s = len(a)

heights.reverse()
a = []
for h in heights:
    l = bisect.bisect_right(a, h)
    if l != len(a):
        a[l] = h
    else:
        a.append(h)
print(len(a))
print(s)
