import sys
import math

def get_ints(): return map(int, sys.stdin.readline().strip().split())


n, k = get_ints()
print(n*10**k // math.gcd(n, 10**k))
