import sys
from itertools import *
from heapq import *
from bisect import *
from math import *
from collections import *
from random import getrandbits
input = sys.stdin.readline
RANDOM = getrandbits(32)
INF = int(1e18)

class Wrapper(int):
    def __init__(self, x):
        int.__init__(x)
    def __hash__(self):
        return super(Wrapper, self).__hash__() ^ RANDOM

def CCW(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)

def check_line_intersection(x1, y1, x2, y2, x3, y3, x4, y4):
    if x1 > x2 or (x1 == x2 and y1 > y2):
        x1, y1, x2, y2 = x2, y2, x1, y1
    if x3 > x4 or (x3 == x4 and y3 > y4):
        x3, y3, x4, y4 = x4, y4, x3, y3

    res1 = CCW(x1, y1, x2, y2, x3, y3)
    res2 = CCW(x1, y1, x2, y2, x4, y4)
    res3 = CCW(x3, y3, x4, y4, x1, y1)
    res4 = CCW(x3, y3, x4, y4, x2, y2)

    if res1 * res2 == res3 * res4 == 0:
        if x1==x2:
            if y2 < y3 or y4 < y1:
                return False
            else:
                return True
        if x2 < x3 or x4 < x1:
            return False
        return True
    elif res1 * res2 <= 0 and res3 * res4 <= 0:
        return True
    else:
        return False

def ray_casting(Figure:list, point):
    x1, y1 = point
    x2, y2 = x1+1, INF
    cnt = 0
    Figure.append(Figure[0])
    for i in range(len(Figure)-1):
        x3, y3 = Figure[i][0], Figure[i][1]
        x4, y4 = Figure[i+1][0], Figure[i+1][1]
        if CCW(x3, y3, x4, y4, x1, y1) == 0:
            if min(x3, x4) <= x1 <= max(x3, x4) and min(y3, y4) <= y1 <= max(y3, y4):
                cnt = 1
                break
        res = check_line_intersection(x1, y1, x2, y2, x3, y3, x4, y4)
        if res:
            cnt += 1
    return (cnt%2 != 0)

def Convex_hull():
    dam.sort()
    inclines = []
    for i in range(1, len(dam)):
        if dam[i][1] == dam[0][1]: 
            incline = 0
        elif dam[i][0] == dam[0][0]:
            incline = float('inf')
        else: 
            incline = (dam[i][1] - dam[0][1])/(dam[i][0] - dam[0][0])
        distance = (dam[i][0] - dam[0][0])**2 + (dam[i][1] - dam[0][1])**2
        inclines.append((incline, distance, i))
    inclines.sort()

    stack = [0]
    for i in range(len(inclines)):
        v = inclines[i][2]
        while len(stack) > 1:
            a, b = stack[-1], stack[-2]
            x1, y1, x2, y2, x3, y3 = dam[b][0], dam[b][1], dam[a][0], dam[a][1], dam[v][0], dam[v][1]
            res = CCW(x1, y1, x2, y2, x3, y3)
            if res > 0:
                break
            else:
                stack.pop()
        stack.append(v)
    
    res = set()
    figure = []
    for i in stack:
        res.add(Wrapper(i))
        figure.append(dam[i])

    pp = [px, py]
    if not ray_casting(figure, pp):
        return []
    return res


n, px, py = map(int, input().split())
dam = [list(map(int, input().split())) for _ in range(n)]

res = 0
while len(dam) >= 3:
    pops = Convex_hull()
    if len(pops) < 3:
        break
    temp = []
    for i in range(len(dam)):
        if Wrapper(i) not in pops:
            temp.append(dam[i])
    dam = temp.copy()
    res += 1
print(res)