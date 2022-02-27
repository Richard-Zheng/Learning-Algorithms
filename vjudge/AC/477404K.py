import sys
import copy


def get_ints(): return map(int, sys.stdin.readline().strip().split())


def ndlist(*args, init=0):
    dp = init
    for x in reversed(args):
        dp = [copy.deepcopy(dp) for _ in range(x)]
    return dp


[n] = get_ints()
graph = [[0]*(n+1) for x in range(n+1)]
while True:
    try:
        [x, y, value] = get_ints()
    except Exception:
        break
    graph[x][y] = value

f = ndlist(n+1, n+1, n+1, n+1)
for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            l = i+j-k
            if l <= 0 or l > n:
                continue
            f[i][j][k][l] = max(f[i-1][j][k-1][l], max(f[i-1][j]
                                [k][l-1], max(f[i][j-1][k-1][l], f[i][j-1][k][l-1])))
            if i == k and j == l:
                f[i][j][k][l] += graph[i][j]
            else:
                f[i][j][k][l] += graph[i][j]+graph[k][l]
print(f[n][n][n][n])
