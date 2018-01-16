moves = [
    ('UL', -2, -1),
    ('UR', -2, 1),
    ('R', 0, 2),
    ('LR', 2, 1),
    ('LL', 2, -1),
    ('L', 0, -2)
]

n = int(input())
i0, j0, i1, j1 = map(int, input().split())

pre = [[None for _ in range(n)] for _ in range(n)]
d = [[-1 for _ in range(n)] for _ in range(n)]

d[i0][j0] = 0
q, qi = [(i0, j0)], 0
while qi < len(q):
    i, j = q[qi]
    for mv, di, dj in moves:
        ii, jj = i + di, j + dj
        if 0 <= ii < n and 0 <= jj < n and d[ii][jj] == -1:
            d[ii][jj] = d[i][j] + 1
            pre[ii][jj] = mv, di, dj
            q.append((ii, jj))
    qi += 1

if d[i1][j1] != -1:
    print(d[i1][j1])
    i, j = i1, j1
    path = []
    while (i, j) != (i0, j0):
        mv, di, dj = pre[i][j]
        path.append(mv)
        i -= di
        j -= dj
    print(' '.join(reversed(path)))
else:
    print('Impossible')
