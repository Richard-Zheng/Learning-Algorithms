import sys


def get_ints(): return map(int, sys.stdin.readline().strip().split())


n, m = get_ints()
rd = [0]*(n+1)
outf = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = get_ints()
    rd[b] += 1
    outf[a].append(b)

ans = 0
s = []
f = [0]*(n+1)
for i in range(1, n+1):
    if rd[i] == 0 and outf[i]:
        s.append(i)
        f[i] = 1
while s:
    x = s.pop()
    if not outf[x]:
        ans += f[x]
    for v in outf[x]:
        f[v] += f[x]
        rd[v] -= 1
        if rd[v] == 0:
            s.append(v)
print(ans)
