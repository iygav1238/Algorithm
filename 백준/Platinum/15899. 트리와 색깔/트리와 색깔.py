import sys
from heapq import *
from bisect import *
from math import *
from collections import *
from random import getrandbits
input = sys.stdin.readline
RANDOM = getrandbits(32)
mod = int(1e9+7)

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
                res += bisect_left(self.tree[l], c+1)
            if ~r & 1:
                res += bisect_left(self.tree[r], c+1)
            l = (l+1)//2
            r = (r-1)//2
        return res

def Tourist(node):
    stack = [(node, 0)]
    depth = 0
    visited[node] = True
    while stack:
        curr, state = stack.pop()
        if state == 0:
            depth += 1
            tour[curr][0] = depth
            stack.append((curr, 1))
            for v in sorted(graph[curr], reverse=True):
                if not visited[v]:
                    stack.append((v, 0))
                    visited[v] = True
        elif state == 1:
            tour[curr][1] = depth

n, m, C = map(int, input().split())
a = [0] + list(map(int, input().split()))

graph = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False]*(n+1)
tour = [[0, 0] for _ in range(n+1)]
Tourist(1)

p = [0]*(n+1)
for i in range(1, n+1):
    s, e = tour[i]
    p[s] = a[i]

tree = MergeSortTree(n+1, p)

res = 0
for _ in range(m):
    v, c = map(int, input().split())
    s, e = tour[v]
    
    res = (res +  tree.query(s, e, c)%mod)%mod
print(res)
