import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


def split_int(i, j):
    return num % (10**(n-i+1)) // (10**(n-j))


n, k = get_ints()
[num] = get_ints()

dp = [[0]*(k+1) for x in range(n+1)]
for i in range(1, n+1):
    dp[i][0] = split_int(1, i)

for i in range(1, n+1):
    for j in range(k):
        if dp[i][j] == 0:
            continue
        for pos in range(i+1, n+1):
            dp[pos][j+1] = max(dp[pos][j+1], dp[i][j] * split_int(i+1, pos))

print(dp[n][k])
