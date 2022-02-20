import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())

def find(x):
    if ufset[x] == x:
        return x
    else:
        ufset[x] = find(ufset[x])
        return ufset[x]

def unite(x, y):
    ufset[find(x)] = find(y)

n, m = get_ints()
ufset = [i for i in range(n+1)]
p = {k:v+1 for v, k in enumerate(get_ints())}

for i in range(m):
    x, y = get_ints()
    unite(x, y)
ans = 0
for i in range(1, n+1):
    if find(i) == find(p[i]):
        ans+=1
print(ans)
    
