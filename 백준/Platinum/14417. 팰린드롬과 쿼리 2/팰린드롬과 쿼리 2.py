import sys
from heapq import *
from bisect import *
from math import *
from collections import *
from random import getrandbits
input = sys.stdin.readline
RANDOM = getrandbits(32)

class Wrapper(int):
    def __init__(self, x):
        int.__init__(x)
    def __hash__(self):
        return super(Wrapper, self).__hash__() ^ RANDOM

class MergeSortTree:
    def __init__(self, n, a):
        self.size = 1 << (ceil(log2(n)))
        self.tree = [[] for _ in range(2*self.size)]
        for i in range(n):
            self.tree[self.size + i] = [a[i]]
        for i in range(self.size-1, 0, -1):
            self.tree[i] = sorted(self.tree[2*i] + self.tree[2*i+1])
    
    def query(self, l, r, c):
        if max(L, R) >= len(p):
            return 0
        l += self.size
        r += self.size
        res = 0
        while l <= r:
            if l & 1:
                res += bisect_left(self.tree[l], c+1)
            if ~r & 1:
                res += bisect_left(self.tree[r], c+1)
            l = (l+1)//2
            r = (r-1)//2
        return res

def manacher(s):
    s = "#" + "#".join(list(s)) + "#"
    ret = [0] * len(s)

    center, right = -1, -1
    for i in range(len(s)):
        if i <= right:
            j = center - (i-center)
            ret[i] = min(ret[j], right-i)
        
        while 0 <= i-ret[i]-1 and i+ret[i]+1 < len(s):
            if s[i-ret[i]-1] != s[i+ret[i]+1]:
                break
            ret[i] += 1

        if right < i+ret[i]:
            center = i
            right = i+ret[i]
        
    return ret[:-1]

s = list(input().strip())
n = len(s)
a = manacher(s)
p = [0]*len(a)

for i in range(len(a)):
    p[i] = i-a[i]

tree = MergeSortTree(len(p), p)

#print(p)
for _ in range(int(input())):
    i, l = map(int, input().split())
    i = 2*i+1
    L, R = min(len(p), i+l-1), len(p)-1
    #print(L, R, i)
    print(tree.query(L, R, i))
