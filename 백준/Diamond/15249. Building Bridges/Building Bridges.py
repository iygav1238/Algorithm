import sys
sys.setrecursionlimit(10**5)
INF = 1e18

class Line:
    def __init__(self, a:int, b:int):
        self.a = a
        self.b = b
    
    def get(self, x:int):
        return self.a * x + self.b

class Li_Chao:
    # 최솟값을 관리하는 Li Chao Tree는 처음에 모든 구간에 y = 0x + inf 직선 하나만 존재하는 상태
    def __init__(self, s:int, e:int):
        # tree_node = [l, r, s, e, Line(a, b)]
        self.tree = [[-1, -1, s, e, Line(0, INF)]]

    # 구간 [s, e]에 직선 v를 추가하는 함수
    # 직선을 추가하게 되면 기존에 있던 직선과 비교한 뒤, 
    # 노드가 관리하는 구간의 절반 이상에서 더 좋은 직선 하나만 저장
    def update(self, node:int, v:Line):
        s = self.tree[node][2]
        e = self.tree[node][3]
        m = (s + e)//2 # mid

        low:Line = self.tree[node][4]
        high:Line = v
        if low.get(s) < high.get(s):  # 여기서 최솟값을 구하므로 더 작은 값 선택
            low, high = high, low
        if low.get(e) >= high.get(e):  # e 지점에서 작은 값을 선택
            self.tree[node][4] = high
            return
        if low.get(m) > high.get(m):  # 중간에서 작은 값을 선택
            self.tree[node][4] = high
            if self.tree[node][1] == -1:
                self.tree[node][1] = len(self.tree)
                self.tree.append([-1, -1, m + 1, e, Line(0, INF)])
            self.update(self.tree[node][1], low)
        else:
            self.tree[node][4] = low
            if self.tree[node][0] == -1:
                self.tree[node][0] = len(self.tree)
                self.tree.append([-1, -1, s, m, Line(0, INF)])
            self.update(self.tree[node][0], high)
    
    # 현재 노드가 갖고 있는 직선이 x에서 갖는 함수 값을 구한 뒤, 
    # x와 구간의 중점의 위치 관계에 따라 왼쪽 혹은 오른쪽 자식에 대해 재귀호출을 해서 
    # 더 작은 값을 반환하도록 수정
    def query(self, node:int, x:int):
        if node == -1: 
            return INF  # 최소값을 구하므로 INF 반환
        s = self.tree[node][2]
        e = self.tree[node][3]
        m = (s + e)//2
        if x <= m: 
            return min(self.tree[node][4].get(x), self.query(self.tree[node][0], x))  # 더 작은 값 반환
        return min(self.tree[node][4].get(x), self.query(self.tree[node][1], x))  # 더 작은 값 반환
    
n = int(sys.stdin.readline())
h = [0] + list(map(int, sys.stdin.readline().split()))
w = [0] + list(map(int, sys.stdin.readline().split()))

dp = [0]*(n+1)
pre = [0]*(n+1)
for i in range(1, n+1):
    pre[i] = pre[i-1] + w[i]

tree = Li_Chao(0, 1e9)
for i in range(2, n+1):
    tree.update(0, Line(-2*h[i-1], h[i-1] * h[i-1] - pre[i-1] + dp[i - 1]))
    dp[i] = tree.query(0, h[i]) + h[i] * h[i] + pre[i-1]
print(dp[n])