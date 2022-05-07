import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[t] = get_ints()
for _ in range(t):
    [n] = get_ints()
    a = sorted(list(get_ints()), reverse=True)
    print(a[0]+a[1])