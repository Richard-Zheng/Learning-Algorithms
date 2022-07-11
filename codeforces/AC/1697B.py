import sys
def gints(): return map(int, sys.stdin.readline().strip().split())

n, q = gints()
p = [0] + sorted(gints(), reverse=True)
for i in range(1,n+1):
    p[i]+=p[i-1]
for _ in range(q):
    x, y = gints()
    print(p[x]-p[x-y])