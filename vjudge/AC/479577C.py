import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())

def inv(a): return pow(a, MOD-2, MOD)

MOD = 1000000007
MAXN = int(1e6)
fact = [1]*(MAXN+1)
for i in range(1, MAXN+1):
    fact[i] = fact[i-1] * i % MOD
a, b, n = get_ints()
ans = 0
for i in range(n+1):
    sum = i * a + (n-i) * b
    flag = True
    for j in str(sum):
        if j != str(a) and j != str(b):
            flag = False
    if not flag:
        continue
    ans += fact[n] * inv(fact[n-i]*fact[i])
    ans %= MOD
print(ans)
