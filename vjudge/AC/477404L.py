import sys


def get_ints(): return map(int, sys.stdin.readline().strip().split())


[t] = get_ints()
MAXM = 2*(10**5)+100
d = [0]*(MAXM+100)
d[0] = 1
d[10] = 1
for i in range(1, MAXM):
    if d[i] > 0:
        d[i+9] += d[i] % (10**9+7)
        d[i+10] += d[i] % (10**9+7)
    d[i] += d[i-1] % (10**9+7)
for _ in range(t):
    n, sm = sys.stdin.readline().strip().split()
    m = int(sm)
    ans = 0
    for k in n:
        ans += d[int(k)+m] % (10**9+7)
    print(ans % (10**9+7))
