from functools import lru_cache
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[t] = get_ints()

for x in range(t):
    n, k = get_ints()
    m = list(get_ints())
    p = list(get_ints())

    dp = [0 for x in range(n+1)]
    ans = 0
    for i in range(n):
        dp[i] = p[i]
        for j in range(0, i):
            if m[i] - m[j] > k:
                dp[i] = max(dp[i], dp[j]+p[i])
        ans = max(ans, dp[i])
    print(ans)
