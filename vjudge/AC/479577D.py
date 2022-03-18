import sys


def get_ints(): return map(int, sys.stdin.readline().strip().split())


def exgcd(a, b):
    if b == 0:
        return (1, 0)  # a*x + b*y = gcd(a, b)
    else:
        x, y = exgcd(b, a % b)  # r_i, r_{i+1}
        return (y, x-(a//b)*y)


a, b = get_ints()
x, y = exgcd(a, b)
print(x % b)
