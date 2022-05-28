import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    s = input()
    ans = 0
    if n % 2 == 1:
        ans += 1
    for i in range(n//2-1, -1, -1):
        if i+1 == n-i-1 or s[i+1] == s[n-i-1]:
            ans += 1
        else:
            break
    for i in range(n//2 if n % 2 == 0 else n//2+1, n):
        if i-1 == n-i-1 or s[i-1] == s[n-i-1]:
            ans += 1
        else:
            break
    print(ans)
