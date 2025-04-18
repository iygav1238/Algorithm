import sys
from collections import deque
input = sys.stdin.readline

n, l = map(int, input().split())
a = list(map(int, input().split()))
q = deque()

res = [0]*n
for i in range(n):
    left = max(0, i-l+1)
    while q and q[-1][0] >= a[i]:
        q.pop()
    q.append((a[i], i))

    while q and q[0][1] < left:
        q.popleft()
    res[i] = q[0][0]
print(*res)