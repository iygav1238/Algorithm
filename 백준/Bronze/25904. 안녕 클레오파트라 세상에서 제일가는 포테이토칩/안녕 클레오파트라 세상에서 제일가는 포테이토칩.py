a,b = map(int,input().split())
X = list(map(int,input().split()))
i = 0
while True:
  Y = [x for x in range(b+a*i,b+a*(i+1))]
  found = False
  for j in range(a):
    if Y[j]>X[j]:
      found = True
      break
  if found:
    break
  i += 1
print(j+1)