import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    n,m = gints()
    a = []
    for _ in range(n):
        a.append(list(gints()))
    imax = [0,0]
    for i in range(n):
        for j in range(m):
            if a[i][j] > a[imax[0]][imax[1]]:
                imax = [i,j]
    imax[0] += 1
    imax[1] += 1
    print(max(imax[0]*imax[1], (n-imax[0]+1)*imax[1], imax[0]*(m-imax[1]+1), (n-imax[0]+1)*(m-imax[1]+1)))