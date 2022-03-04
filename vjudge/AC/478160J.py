import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())


n, m, s, t = get_ints()
graph = [[0]*(n+1) for _ in range(n+1)]
for _ in range(m):
    x, y, w = get_ints()
    graph[x][y] = w
    graph[y][x] = w

dist = [float('inf')]*(n+1)
dist[s] = 0
q = set(range(1, n+1))
while q:
    u = min(q, key=lambda x: dist[x])
    q.remove(u)
    for i in range(1, n+1):
        if i in q and graph[u][i] != 0:
            dist[i] = min(dist[i], dist[u]+graph[u][i])
print(dist[t])
