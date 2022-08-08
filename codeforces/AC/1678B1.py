import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    s = input()
    ans = 0
    for i in range(0, n, 2):
        if s[i] != s[i+1]:
            ans+=1
    print(ans)
