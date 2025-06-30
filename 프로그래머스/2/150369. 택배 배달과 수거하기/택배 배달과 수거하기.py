def solution(cap, n, deliveries, pickups):
    answer = 0
    a = deliveries
    b = pickups
    while (len(a) or len(b)):
        while len(a) and a[-1] == 0:
            a.pop()
        while len(b) and b[-1] == 0:
            b.pop()
        answer += max(len(a), len(b))*2
        
        tot = 0
        while len(a) and tot < cap:
            if (tot + a[-1] <= cap):
                tot += a[-1]
                a.pop()
            else:
                diff = cap - tot
                tot = cap
                a[-1] -= diff
        
        tot = 0
        while len(b) and tot < cap:
            if (tot + b[-1] <= cap):
                tot += b[-1]
                b.pop()
            else:
                diff = cap - tot
                tot = cap
                b[-1] -= diff
    
    return answer