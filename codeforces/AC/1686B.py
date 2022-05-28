import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    [n] = gints()
    p = list(gints())
    dp = [0]*(n+1)
    for i in range(n):
        if i == 0:
            dp[i] = 0
            continue
        dp[i] = max(dp[i-1], dp[i-2]+(p[i-1] > p[i]))
    print(dp[n-1])