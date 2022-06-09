from math import floor
import sys

def gints(): return map(int, input().split())


[t] = gints()
for _ in range(t):
    a,b,c = gints()
    print(a+b+c, b+c, c)