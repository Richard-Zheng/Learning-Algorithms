import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


n,m = gints()
a = [0] + list(gints())
right = [0]
for i in range(1, n):
    right.append(a[i]-a[i+1] if a[i] > a[i+1] else 0)
    right[-1] += right[-2]
left = [0]
for i in range(2, n+1):
    left.append(a[i]-a[i-1] if a[i] > a[i-1] else 0)
    left[-1] += left[-2]
for _ in range(m):
    s, t = gints()
    if s < t:
        print(right[t-1]-right[s-1])
    else:
        print(abs(left[t-1]-left[s-1]))
