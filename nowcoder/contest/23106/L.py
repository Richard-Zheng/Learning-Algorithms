from math import sqrt
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

dir = {
    'U': [0, 1],
    'D': [0, -1],
    'R': [1, 0],
    'L': [-1, 0],
}

[t] = get_ints()
for x in range(t):
    [n] = get_ints()
    x = 0
    y = 0
    ans = 0
    m = sys.stdin.readline().strip()
    for c in m:
        x += dir[c][0]
        y += dir[c][1]
        ans = max(ans, sqrt(x**2 + y**2))
    print(ans)