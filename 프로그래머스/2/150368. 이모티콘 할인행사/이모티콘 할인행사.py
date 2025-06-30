from itertools import product

def solution(users, emoticons):
    ratios = (10, 20, 30, 40)
    m = len(emoticons)

    answer = [0, 0]
    for p in product(ratios, repeat=m):
        cur = [0, 0]
        for user in users:
            a, b = user
            cost = 0
            for i in range(m):
                if a <= p[i]:
                    cost += emoticons[i]*(100 - p[i])//100
            if cost >= b:
                cur[0] += 1
            else:
                cur[1] += cost
        if cur[0] > answer[0] or (cur[0] == answer[0] and cur[1] > answer[1]):
            answer = cur[:]
    return answer
