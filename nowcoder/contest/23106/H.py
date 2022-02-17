from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[n] = get_ints()
a = list(get_ints())
for i in range(n):
    a[i] -= 500
a.sort()
ans = 0
for num in a:
    i = bisect_left(a, -num)
    ans += i*(-num)
    ans += (n-i)*num
    ans += abs(num)
print(ans)