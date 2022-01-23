from bisect import bisect_left
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[n] = get_ints()
a = [0] + list(get_ints())
b = [0] + list(get_ints())
map = [0 for i in range(n+1)]
for i, v in enumerate(a):
    map[v] = i

f = []
for i in range(1, n+1):
    pos = bisect_left(f, map[b[i]])
    if pos == len(f):
        f.append(map[b[i]])
    else:
        f[pos] = map[b[i]]
print(len(f))
