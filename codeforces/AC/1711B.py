import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    n,m=gints()
    a = [0] + list(gints())
    pair = []
    cntp = [0]*(n+1)
    for _ in range(m):
        x,y=gints()
        cntp[x]+=1
        cntp[y]+=1
        pair.append((x,y))
    if m % 2 == 0:
        print(0)
        continue
    ans = int(1e9)
    for i in pair:
        if cntp[i[0]]%2==0 and cntp[i[1]]%2==0:
            ans=min(ans, a[i[0]]+a[i[1]])
    for i in range(1,n+1):
        if cntp[i]%2==1:
            ans = min(ans, a[i])
    print(ans)
