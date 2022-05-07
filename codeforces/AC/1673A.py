import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    s = input()
    ss = [0]*(len(s)+1)
    for i in range(1, len(s)+1):
        ss[i] = ss[i-1] + ord(s[i-1]) - ord('a') + 1
    if len(s) % 2 == 0:
        print('Alice', ss[len(s)])
        continue
    if len(s) == 1:
        print('Bob', ss[len(s)])
        continue
    
    mid = ss[len(s)-1] - ss[1]
    f = ss[1]
    l = ss[len(s)] - ss[len(s)-1]
    print('Alice', max(mid+f-l,mid+l-f))
