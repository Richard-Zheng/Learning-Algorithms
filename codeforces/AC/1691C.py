import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    n,k = gints()
    s = sys.stdin.readline().strip()
    ansadd = 0
    onecnt = 0

    seenone = False
    for i in range(n):
        onecnt += int(s[i])
        if s[i] == '1':
            if not seenone:
                firstone = i
            seenone = True
            lastone = i
    if onecnt > 0 and (n-1-lastone) <= k:
        k-= n-1-lastone
        ansadd+=1
        onecnt-=1
    if onecnt > 0 and firstone <= k:
        ansadd += 10
        onecnt -= 1
    print(11*onecnt+ansadd)