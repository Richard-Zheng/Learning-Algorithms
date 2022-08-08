import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    [a,*p] = gints()
    ans = 0
    for i in p:
        if i > a:
            ans+=1
    print(ans)
