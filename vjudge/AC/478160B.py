import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())


def find(x):
    if x == ufset[x]:
        return x
    else:
        ufset[x] = find(ufset[x])
        return ufset[x]


def union(x, y):
    ufset[find(x)] = find(y)


n, m = get_ints()

ufset = [i for i in range(n+m+10)]
flag = False

for i in range(1, n+1):
    input = list(get_ints())
    if input[0] == 0:
        continue
    else:
        flag = True
        for x in input[1:]:
            union(i, n+x)

if not flag:
    print(n)
else:
    for i in range(1, n+1):
        find(i)
    print(len(set(ufset[1:n+1]))-1)
