import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())


n = int(sys.stdin.readline().strip()[-2:])
if n % 4 == 0:
    print(4)
else:
    print(0)
