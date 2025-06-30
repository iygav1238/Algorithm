def solution(info, n, m):
    k = len(info)
    
    # dp[i][a][b] i번째를 훔친 시점에서 A흔적이 총 a, B 흔적이 총 b인것이 가능한가? 1 : 0 
    dp = [[[0]*m for _ in range(n)] for _ in range(k)]
    x, y = info[0]
    if x < n:
        dp[0][x][0] = 1
    if y < m:
        dp[0][0][y] = 1
    
    for i in range(1, k):
        x, y = info[i]
        for a in range(n):
            for b in range(m):
                if a-x >= 0:
                    dp[i][a][b] = max(dp[i][a][b], dp[i-1][a-x][b])
                if b-y >= 0:
                    dp[i][a][b] = max(dp[i][a][b], dp[i-1][a][b-y])
    
    for a in range(n):
        for b in range(m):
            if (dp[k-1][a][b] == 1):
                return a
    return -1