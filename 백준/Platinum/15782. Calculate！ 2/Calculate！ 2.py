import sys
from math import ceil, log2
input = sys.stdin.readline

class LazySegTree:
    def __init__(self):
        size = 1 << (ceil(log2(n))+1)
        self.tree = [0] * size
        self.lazy = [0] * size
        self.build(0, n - 1, 1)

    def build(self, start, end, idx):
        if start == end:
            self.tree[idx] = a[start]
            return
        mid = (start + end) // 2
        self.build(start, mid, idx * 2)
        self.build(mid + 1, end, idx * 2 + 1)
        self.tree[idx] = self.tree[idx * 2] ^ self.tree[idx * 2 + 1]

    def update_lazy(self, start, end, idx):
        if self.lazy[idx] != 0:
            if (end - start + 1) % 2: 
                self.tree[idx] ^= self.lazy[idx]
            if start < end:
                self.lazy[idx * 2] ^= self.lazy[idx]
                self.lazy[idx * 2 + 1] ^= self.lazy[idx]
            self.lazy[idx] = 0

    def update(self, start, end, idx, left, right, diff):
        self.update_lazy(start, end, idx)
        if right < start or left > end:
            return
        if left <= start and end <= right:
            self.lazy[idx] ^= diff
            self.update_lazy(start, end, idx)
            return
        mid = (start + end) // 2
        self.update(start, mid, idx * 2, left, right, diff)
        self.update(mid + 1, end, idx * 2 + 1, left, right, diff)
        self.tree[idx] = self.tree[idx * 2] ^ self.tree[idx * 2 + 1]

    def query(self, start, end, idx, left, right):
        self.update_lazy(start, end, idx)
        if right < start or left > end:
            return 0
        if left <= start and end <= right:
            return self.tree[idx]
        mid = (start + end) // 2
        lsum = self.query(start, mid, idx * 2, left, right)
        rsum = self.query(mid + 1, end, idx * 2 + 1, left, right)
        return lsum ^ rsum

def Tourist(node):
    stack = [(node, 0)]
    depth = -1
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

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
tour = [[0, 0] for _ in range(n+1)]
w = list(map(int, input().split()))
visited = [False]*(n+1)
Tourist(1)

a = [0]*n
for i in range(n):
    a[tour[i+1][0]] = w[i]
    
tree = LazySegTree()
for _ in range(m):
    what, *q = map(int, input().split())
    if what == 1:
        x = q[0]
        i, j = tour[x]
        print(tree.query(0, n - 1, 1, i, j))
    else:
        x, y = q
        i, j = tour[x]
        tree.update(0, n - 1, 1, i, j, y)