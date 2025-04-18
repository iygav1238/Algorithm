import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
res = 0
for i in range(n-2):
    while a[i] != 0 and a[i+1] > a[i] and a[i+1] > a[i+2]:
        res += 5
        a[i] -= 1
        a[i+1] -= 1
    
    v = min(a[i], a[i+1], a[i+2])
    res += v*7
    a[i] -= v
    a[i+1] -= v
    a[i+2] -= v

for i in range(n-1):
    v = min(a[i], a[i+1])
    res += v*5
    a[i] -= v
    a[i+1] -= v
print(res + 3*sum(a))