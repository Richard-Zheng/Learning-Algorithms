import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


[t] = get_ints()
for i in range(t):
    n, m = get_ints()
    if m == 1:
        if n == 1:
            print('1')
        else:
            print('-1')
    else:
        print(((n-1)+m-1-1)//(m-1)*2-1)