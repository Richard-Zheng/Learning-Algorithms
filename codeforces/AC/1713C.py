from itertools import permutations
import sys
import math


def gints(): return map(int, sys.stdin.readline().strip().split())


def check(p):
    for i in range(len(p)):
        if math.sqrt(p[i]+i) != math.floor(math.sqrt(p[i]+i)):
            return False
    return True

def answ(n):
    if n == 0:
        return [0]
    u=math.floor(math.sqrt(n*2))**2
    if u == n:
        return list(range(n, u-n-1, -1))
    return answ(u-n-1)+list(range(n, u-n-1, -1))

[t] = gints()
for _ in range(t):
    [n] = gints()
    print(*answ(n-1))
    #for p in permutations(range(n)):
        #if check(p):
            #print(n,p)
