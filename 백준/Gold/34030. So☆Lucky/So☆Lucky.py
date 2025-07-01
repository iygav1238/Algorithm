import sys
input = sys.stdin.readline
INF = float('inf')

n = int(input())
a = list(map(int, input().split()))

odd, even = [i for i in a if (i%2 == 1)], [i for i in a if (i%2 == 0)]

ok = True
for i in range(1, len(odd)):
    if odd[i-1] > odd[i]:
        ok = False
for i in range(1, len(even)):
    if even[i-1] > even[i]:
        ok = False

print("So Lucky" if ok else "Unlucky")

ok = True
last = b = -INF
for i in range(n):
    if (i == 0) or (a[i]%2 != a[i-1]%2):
        last = b
        b = -INF
    if last > a[i]:
        ok = False
        break     
    b = max(b, a[i])

print("So Lucky" if ok else "Unlucky")