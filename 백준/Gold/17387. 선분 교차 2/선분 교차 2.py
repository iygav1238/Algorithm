def CCW(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)

def solution(x1, y1, x2, y2, x3, y3, x4, y4):
    # 편의를 위해 x1은 x2보다, x3은 x4보다 왼쪽 아래가 되게 함
    if x1 > x2 or (x1 == x2 and y1 > y2):
        x1, y1, x2, y2 = x2, y2, x1, y1
    if x3 > x4 or (x3 == x4 and y3 > y4):
        x3, y3, x4, y4 = x4, y4, x3, y3

    res1 = CCW(x1, y1, x2, y2, x3, y3) # A B C
    res2 = CCW(x1, y1, x2, y2, x4, y4) # A B D
    res3 = CCW(x3, y3, x4, y4, x1, y1) # C D A
    res4 = CCW(x3, y3, x4, y4, x2, y2) # C D B

    if res1 * res2 == res3 * res4 == 0:
        if x1==x2:
            if y2 < y3 or y4 < y1:
                print(0)
            else:
                print(1)
            return
        if x2 < x3 or x4 < x1:
            print(0)
            return
        print(1)
    elif res1 * res2 <= 0 and res3 * res4 <= 0:
        print(1)
    else:
        print(0)
    
x1, y1, x2, y2 = map(int, input().split()) # A B
x3, y3, x4, y4 = map(int, input().split()) # C D

solution(x1, y1, x2, y2, x3, y3, x4, y4)