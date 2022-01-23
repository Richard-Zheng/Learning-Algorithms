import sys
n, k = map(int, sys.stdin.readline().strip().split())
arr = list(map(int, sys.stdin.readline().strip().split()))
sorted = sorted(range(len(arr)), key=lambda k: arr[k])
minw = {}
for i in sorted:
    for j in range(k):
        if i-j not in minw:
            minw[i-j] = arr[i]
for i in range(n-k+1):
    print(minw[i], end=' ')
print('')
maxw = {}
for i in reversed(sorted):
    for j in range(k):
        if i-j not in maxw:
            maxw[i-j] = arr[i]
for i in range(n-k+1):
    print(maxw[i], end=' ')
