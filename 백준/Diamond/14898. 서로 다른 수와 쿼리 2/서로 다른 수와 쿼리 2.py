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
        l += self.size
        r += self.size
        res = 0
        while l <= r:
            if l & 1:
                res += bisect_left(self.tree[l], c)
            if ~r & 1:
                res += bisect_left(self.tree[r], c)
            l = (l+1)//2
            r = (r-1)//2
        return res

n = int(input())
a = [0] + list(map(int, input().split()))

p = [0]*(n+1)
appear = defaultdict(int)
for i in range(1, n+1):
    p[i] = appear[Wrapper(a[i])]
    appear[Wrapper(a[i])] = i

#print(p)
tree = MergeSortTree(n+1, p)

res = 0
for _ in range(int(input())):
    x, r = map(int, input().split())
    l = x + res
    res = tree.query(l, r, l)
    print(res)