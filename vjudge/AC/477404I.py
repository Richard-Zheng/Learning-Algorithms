import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[n, l, k] = get_ints()
coord = list(get_ints())
coord.append(l)
speed = list(get_ints())

# dp[i][j]: min time to drive to *i* as *j* signs are removed
dp = [[float('inf')]*(k+1) for x in range(n+1)]

dp[0][0] = 0
for i in range(1, n+1):
    dp[i][0] = dp[i-1][0] + speed[i-1] * (coord[i] - coord[i-1])

for i in range(n):
    for j in range(k+1):
        if dp[i][j] == float('inf'):
            continue
        for pos in range(i+1, n+1):
            if j+(pos-i-1) <= k:
                dp[pos][j+(pos-i-1)] = min(dp[pos][j+(pos-i-1)],
                                           dp[i][j] + speed[i] * (coord[pos] - coord[i]))

ans = float('inf')
for j in range(k+1):
    ans = min(ans, dp[n][j])
print(ans)
