from functools import lru_cache
import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())
def distance(x1, y1, x2, y2): return pow((x1-x2),2) + pow((y1-y2),2)

x0, y0, x1, y1 = get_ints()
[n] = get_ints()

@lru_cache(maxsize=n)
def get_overhead(index, rad0, rad1):
    if (index >= n):
        return rad0 + rad1
    return min(get_overhead(index + 1, max(rad0, dis[index][0]), rad1), get_overhead(index+1, rad0, max(rad1,dis[index][1])))

dis = [[0 for x in range(2)] for y in range(n)]
for i in range(n):
    x, y = get_ints()
    dis[i][0] = distance(x0, y0, x, y)
    dis[i][1] = distance(x1, y1, x, y)
print(get_overhead(0, 0, 0))

