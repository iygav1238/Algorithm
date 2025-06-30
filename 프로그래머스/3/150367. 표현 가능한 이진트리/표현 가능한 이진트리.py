def chk(num):
    s = bin(num)[2:]
    h = 0
    while (1 << h) - 1 < len(s):
        h += 1
    L = (1 << h) - 1
    bits = ['0'] * (L - len(s)) + list(s)
    stack = [(0, L - 1)]
    while stack:
        l, r = stack.pop()
        if l > r:
            continue
        mid = (l + r) // 2
        if bits[mid] == '0':
            if '1' in bits[l:mid] or '1' in bits[mid + 1:r + 1]:
                return 0
        else:
            stack.append((l, mid - 1))
            stack.append((mid + 1, r))
    return 1
    
def solution(numbers):
    return [chk(num) for num in numbers]
