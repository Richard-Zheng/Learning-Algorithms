import sys


def gints(): return map(int, sys.stdin.readline().strip().split())


[t] = gints()
for _ in range(t):
    s = list(input())
    needzuo = len(s)//2
    needyou = len(s)//2
    pos = []
    for i, c in enumerate(s):
        if c == '(':
            needzuo -= 1
        elif c == ')':
            needyou -= 1
        else:
            pos.append(i)
    for i, p in enumerate(pos):
        if i == needzuo-1:
            s[p] = ')'
            continue
        elif i == needzuo:
            s[p] = '('
            continue
        if i < needzuo:
            s[p] = '('
        else:
            s[p] = ')'

    flag = True
    balance = 0
    for c in s:
        if c == '(':
            balance += 1
        elif c == ')':
            balance -= 1
        if balance < 0:
            flag = False
    if needzuo == 0 or needyou == 0:
        flag = False
    print('NO' if flag else 'YES')
