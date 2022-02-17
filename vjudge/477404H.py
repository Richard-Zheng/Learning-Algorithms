import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[t] = get_ints()
for case in range(1, t+1):
    sys.stdin.readline()
    [n] = get_ints()
    gold = list(get_ints())
    