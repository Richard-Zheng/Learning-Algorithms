import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    s = input()
    ans = 0
    for i in range(1,n):
        if s[i] != s[i-1]:
            ans += i
    print(ans+n)