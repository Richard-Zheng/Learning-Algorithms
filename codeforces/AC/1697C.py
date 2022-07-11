from functools import reduce
import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[q] = gints()
for _ in range(q):
    [n] = gints()
    s = input()
    t = input()
    if ''.join(s.split('b')) != ''.join(t.split('b')):
        print('NO')
        continue
    j = 0
    flag = True
    for i in range(n):
        if s[i] == 'b':
            continue
        while t[j] == 'b':
            j += 1
        if s[i] != t[j] or (s[i]=='a' and i>j) or (s[i]=='c' and i<j):
            flag = False
            break
        j+=1
    print('YES' if flag else 'NO')