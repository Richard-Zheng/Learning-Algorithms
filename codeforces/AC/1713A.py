import sys

def gints(): return map(int, sys.stdin.readline().strip().split())

[t] = gints()
for _ in range(t):
    [n] = gints()
    maxy,maxx,miny,minx=0,0,0,0
    for i in range(n):
        x,y=gints()
        if x==0:
            if y < 0:
                miny=min(miny,y)
            else:
                maxy=max(maxy, y)
        else:
            if x < 0:
                minx=min(minx,x)
            else:
                maxx=max(maxx,x)
    print((maxx+maxy+abs(minx)+abs(miny))*2)
    