import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    n, m = gints()
    a = []
    for _ in range(n):
        a.append(list(gints()))

    if (n+m)%2 == 0:
        print('NO')
        continue
    mina = [[0]*m for _ in range(n)]
    maxa = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if i == 0:
                if j == 0:
                    mina[i][j] = a[i][j]
                    maxa[i][j] = a[i][j]
                else:
                    mina[i][j] = a[i][j] + mina[i][j-1]
                    maxa[i][j] = a[i][j] + maxa[i][j-1]
            elif j == 0:
                mina[i][j] = a[i][j] + mina[i-1][j]
                maxa[i][j] = a[i][j] + maxa[i-1][j]
            else:
                mina[i][j] = a[i][j] + min(mina[i-1][j], mina[i][j-1])
                maxa[i][j] = a[i][j] + max(maxa[i-1][j], maxa[i][j-1])
    if mina[n-1][m-1] <= 0 and maxa[n-1][m-1] >= 0:
        print('YES')
    else:
        print('NO')
