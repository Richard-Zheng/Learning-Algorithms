import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for i in range(t):
    [n] = gints()
    s = list(gints())
    l = 0
    r = 0
    ans = []
    flag=True
    while r < n:
        if r < n-1 and s[r]==s[r+1]:
            ans.append(r+1+1)
        elif l==r:
            flag=False
            break
        else:
            ans.append(l+1)
            l = r+1
        r+=1
    if flag:
        print(*ans)
    else:
        print("-1")
            