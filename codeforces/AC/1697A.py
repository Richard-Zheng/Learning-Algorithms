def gints(): return map(int, input().split())

[t] = gints()
for _ in range(t):
    n,m = gints()
    a = list(gints())
    ans = sum(a)-m
    if ans > 0:
        print(ans)
    else:
        print(0)
