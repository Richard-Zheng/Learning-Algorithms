import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


t,m = get_ints()
time = [0 for x in range(m+1)]
price = [0 for x in range(m+1)]
for i in range(1, m+1):
    time[i], price[i] = get_ints()

dp = [[0 for x in range(t+1)] for x in range(m+1)]

for i in range(1, m+1):
    for j in range(1, t+1):
        dp[i][j] = dp[i-1][j]
        if j >= time[i]:
            dp[i][j] = max(dp[i][j], dp[i-1][j-time[i]]+price[i])
        
print(dp[m][t])