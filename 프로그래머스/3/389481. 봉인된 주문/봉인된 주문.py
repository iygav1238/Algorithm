def solution(n, bans):
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    answer = ''
    p = [[] for _ in range(12)]
    for i in bans:
        p[len(i)].append(i)
    for i in range(1, 12):
        p[i].sort(reverse=True)
    
    size = 0
    for i in range(1, 12):
        cur = pow(26, i) - len(p[i])
        if cur >= n:
            size = i
            break
        else:
            n -= cur
    
    for i in range(size):
        back = pow(26, size-i-1)
        for j in alpha:
            cnt = 0
            for k in range(len(p[size])-1, -1, -1):
                s = p[size][k][:i+1]
                if s == (answer+j):
                    cnt += 1
                else:
                    break
            
            cur = back - cnt
            if cur >= n:
                answer += j
                break
            else:
                n -= cur
                while p[size]:
                    s = p[size][-1][:i+1]
                    if s == (answer+j):
                        p[size].pop()
                    else:
                        break
    return answer