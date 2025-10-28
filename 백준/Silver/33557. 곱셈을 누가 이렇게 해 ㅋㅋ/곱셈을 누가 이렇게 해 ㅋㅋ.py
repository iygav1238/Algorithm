import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b = map(str, input().split())
    x, y = int(a), int(b)
    ori = x*y

    if len(a) < len(b):
        a, b = b, a
    while len(a) > len(b):
        b = "1" + b
    
    n = len(a)
    m = ""
    for i in range(n):
        cur = int(a[i])*int(b[i])
        m += str(cur)
    m = int(m)
    if m == ori:
        print(1)
    else:
        print(0)
    
