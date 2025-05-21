n = int(input())
res = 0
for i in range(2, n+1):
    res = 2*res + pow(-1, i)
print(res)