from itertools import product, combinations
from bisect import bisect_left

def solution(dice):
    n = len(dice)
    k = n//2
    mx = 0
    answer = []

    for comb in combinations(range(n), k):
        opp = [i for i in range(n) if i not in comb]
        p = [sum(dice[i][face] for i,face in zip(opp, faces))
             for faces in product(range(6), repeat=k)]
        p.sort()

        score = 0
        for faces in product(range(6), repeat=k):
            s = sum(dice[i][face] for i,face in zip(comb, faces))
            score += bisect_left(p, s)

        if score > mx:
            mx = score
            answer = comb

    return [i+1 for i in answer]