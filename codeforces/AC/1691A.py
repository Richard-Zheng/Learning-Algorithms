import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    gints()
    a = list(gints())
    cnt = [0]*2
    for i in a:
        cnt[i&1]+=1
    print(min(cnt))