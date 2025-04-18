import sys

n, b, c = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
if c >= b:
    print(sum(a)*b)
    exit()
res = 0
for i in range(n-2):
    if a[i] != 0 and a[i+1] > a[i] and a[i+1] > a[i+2]:
        min_value = min(a[i], a[i+1] - a[i+2])
        res += min_value * (b + c)
        a[i] -= min_value
        a[i+1] -= min_value

    
    v = min(a[i], a[i+1], a[i+2])
    res += v*(b+2*c)
    a[i] -= v
    a[i+1] -= v
    a[i+2] -= v

for i in range(n-1):
    v = min(a[i], a[i+1])
    res += v*(b+c)
    a[i] -= v
    a[i+1] -= v
print(res + b*sum(a))