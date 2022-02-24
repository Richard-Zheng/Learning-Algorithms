import collections
import sys


def get_ints(): return map(int, sys.stdin.readline().strip().split())


[t] = get_ints()
for i in range(t):
    cnt = collections.Counter(sys.stdin.readline().strip())
    twos = ''
    ones = ''
    for v in cnt:
        if cnt[v] == 2:
            twos += v
        else:
            ones += v
    print(twos, twos, ones, sep='')
