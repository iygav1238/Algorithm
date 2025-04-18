import sys
from fractions import Fraction
from decimal import Decimal as D
input = sys.stdin.readline
INF = 523518523518

def ccw(p1, p2, p3):
    p1 = [D(p1[0]), D(p1[1])]
    p2 = [D(p2[0]), D(p2[1])]
    p3 = [D(p3[0]), D(p3[1])]
    return D(p2[0]-p1[0])*D(p3[1]-p1[1]) - D(p3[0]-p1[0])*D(p2[1]-p1[1])

def check(a, b, c, d):
    if ccw(a, b, c) * ccw(a, b, d) == 0:
        if ccw(c, d, a) * ccw(c, d, b) == 0:
            if a > b:
                a, b = b, a
            if c > d:
                c, d = d, c
            if b >= c and a <= d:
                return True
            else:
                return False
    if ccw(a, b, c) * ccw(a, b, d) <= 0:
        if ccw(c, d, a) * ccw(c, d, b) <= 0:
            return True
    return False

def intersect(x1, y1, x2, y2, x3, y3, x4, y4):
    point = [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]

    res = []
    if check(point[0], point[1], point[2], point[3]):
        res.append(True)
        try:
            x = D((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/D((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4))
            y = D((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/D((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4))
            res += [x, y]
        except:
            if point[0] > point[1]:
                point[0], point[1] = point[1], point[0]
            if point[2] > point[3]:
                point[2], point[3] = point[3], point[2]
            if point[1] == point[2]:
                res += [point[1][0], point[1][1]]
            elif point[0] == point[3]:
                res += [point[0][0], point[0][1]]
    else:
        res.append(False)
    return res

# 점이 도형 안에 있으면 True, 아니면 False
def ray_casting(Figure:list, point):
    x1, y1 = point
    x2, y2 = x1+1, INF
    cnt = 0
    for i in range(len(Figure)-1):
        x3, y3 = Figure[i][0], Figure[i][1]
        x4, y4 = Figure[i+1][0], Figure[i+1][1]
        res = intersect(x1, y1, x2, y2, x3, y3, x4, y4)
        if res[0]:
            cnt += 1
    if cnt%2 != 0:
        return True
    return False

def polygonArea(X:list, Y:list, numPoints:int):
    area = 0
    j = numPoints-1; 

    for i in range(numPoints):
        area += D(D(X[j])+D(X[i])) * D(D(Y[j])-D(Y[i]))
        j = i
    return abs(D(area)/D(2))

def convex_hull(A:list):
    A.sort()

    down = []
    for i in range(len(A)):
        while len(down) > 1 and ccw(down[-2], down[-1], A[i]) <= 0:
            down.pop()
        down.append(A[i])

    up = []
    for i in range(len(A) - 1, -1, -1):
        while len(up) > 1 and ccw(up[-2], up[-1], A[i]) <= 0: 
            up.pop()
        up.append(A[i])

    return down[:-1] + up[:-1]

n, m = map(int, input().split())
p1 = [list(map(int, input().split())) for _ in range(n)]
p2 = [list(map(int, input().split())) for _ in range(m)]

p1.append(p1[0])
p2.append(p2[0])

X, Y = [], []
pp = []
for i in range(n):
    x1, y1 = p1[i]
    if ray_casting(p2, p1[i]):
        pp.append((x1, y1))

    x2, y2 = p1[i+1]
    for j in range(m):
        x3, y3 = p2[j]
        x4, y4 = p2[j+1]
            
        p = intersect(x1, y1, x2, y2, x3, y3, x4, y4)
        if p[0]:
            pp.append((p[1], p[2]))

for i in range(m):
    x1, y1 = p2[i]
    if ray_casting(p1, p2[i]):
        pp.append((x1, y1))

    x2, y2 = p2[i+1]
    for j in range(n):
        x3, y3 = p1[j]
        x4, y4 = p1[j+1]
            
        p = intersect(x1, y1, x2, y2, x3, y3, x4, y4)
        if p[0]:
            pp.append((p[1], p[2]))

pp = list(set(tuple(pp)))
ch = convex_hull(pp)
for i in range(len(ch)):
    X.append(ch[i][0])
    Y.append(ch[i][1])
res = polygonArea(X, Y, len(X))

print(res)