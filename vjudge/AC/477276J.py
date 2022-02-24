import sys

def get_ints(): return map(int, sys.stdin.readline().strip().split())

n, m = get_ints()
arr = list(get_ints())
arr = [0] + arr

# presum
for i in range(1, n+1):
    arr[i] += arr[i-1]

queue = [0]
ans = -1000
for i in range(1, n+1):
    while queue and i - queue[0] > m:
        queue.pop(0)
    ans = max(ans, arr[i] - arr[queue[0]])
    while queue and arr[queue[-1]] >= arr[i]:
        queue.pop(-1)
    queue.append(i)

print(ans)
