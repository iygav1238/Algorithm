import sys
from math import ceil, log2

def merge(left: list, right: list) -> list:
    return [
        max(left[0], left[3] + right[0]),
        max(right[1], right[3] + left[1]),
        max(left[2], right[2], left[1] + right[0]),
        left[3] + right[3]
    ]

def query(i: int, j: int) -> int:
    i += size
    j += size
    left = [-INF, -INF, -INF, 0]
    right = [-INF, -INF, -INF, 0]

    while i <= j:
        if i % 2 == 1:
            left = merge(left, st[i])
            i += 1
        if j % 2 == 0:
            right = merge(st[j], right)
            j -= 1
        i //= 2
        j //= 2

    result = merge(left, right)
    return result[2]  # MAX value

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
INF = float('inf')

size = 2 ** ceil(log2(n))
st = [[-INF, -INF, -INF, 0] for _ in range(2 * size)]

for i in range(n):
    st[size + i] = [a[i], a[i], a[i], a[i]]

for i in range(size - 1, 0, -1):
    st[i] = merge(st[2 * i], st[2 * i + 1])

for _ in range(int(sys.stdin.readline())):
    i, j = map(int, sys.stdin.readline().split())
    print(query(i - 1, j - 1))