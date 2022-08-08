import sys

def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    [n] = gints()
    s = ' ' + input()
    ans = 0
    dp = [[1,1] for _ in range(n+1)]
    for i in range(1, (n//2)+1):
        if s[2*i-1] == s[2*i]:
            now = int(s[2*i])
            dp[i][now] = min(dp[i-1][now], dp[i-1][now^1]+1)
            dp[i][now^1] = 1000000000
        else:
            ans += 1
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1)
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]+1)
    print(ans, min(dp[n//2][0], dp[n//2][1]))
