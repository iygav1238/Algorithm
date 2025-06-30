def getParent(parent, x):
    if parent[x] != x:
        parent[x] = getParent(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    a = getParent(parent, a)
    b = getParent(parent, b)
    if a == b:
        return a
    if a < b:
        parent[b] = a
        return a
    else:
        parent[a] = b
        return b

def solution(commands):
    parent = [i for i in range(2501)]
    a = ["EMPTY"] * 2501
    answer = []
    for c in commands:
        cmd = c.split()
        if cmd[0] == "UPDATE":
            if len(cmd) == 4:
                r, c, v = int(cmd[1]), int(cmd[2]), cmd[3]
                idx = 50 * (r - 1) + c
                root = getParent(parent, idx)
                for i in range(1, 2501):
                    if getParent(parent, i) == root:
                        a[i] = v
            else:
                v1, v2 = cmd[1], cmd[2]
                for i in range(1, 2501):
                    if a[i] == v1:
                        a[i] = v2
        elif cmd[0] == "MERGE":
            r1, c1, r2, c2 = map(int, cmd[1:])
            i = 50 * (r1 - 1) + c1
            j = 50 * (r2 - 1) + c2
            root = union(parent, i, j)
            v = a[i] if a[i] != "EMPTY" else a[j]
            for k in range(1, 2501):
                if getParent(parent, k) == root:
                    a[k] = v
        elif cmd[0] == "UNMERGE":
            r, c = map(int, cmd[1:])
            idx = 50 * (r - 1) + c
            root = getParent(parent, idx)
            keep = a[idx]
            for i in range(1, 2501):
                if getParent(parent, i) == root:
                    parent[i] = i
                    a[i] = "EMPTY"
            a[idx] = keep
        else:
            r, c = map(int, cmd[1:])
            idx = 50 * (r - 1) + c
            answer.append(a[getParent(parent, idx)])
    return answer
