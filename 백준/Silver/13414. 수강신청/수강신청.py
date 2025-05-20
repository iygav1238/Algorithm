import sys
input = sys.stdin.readline

k, l = map(int, input().split())
dic = {}
for i in range(l):
    s = input().rstrip()
    dic[s] = i

res = []
for i in dic:
    res.append((dic[i], i))
res.sort()

for i in range(min(k, len(res))):
    print(res[i][1])