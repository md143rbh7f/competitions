INF = float('inf')

def solve(self, t0, n0, t1, n1):
    n, ans = len(t0), 0
    es, seen = [[] for i in range(n)], [False] * n
    for i, (f, g, a, b) in enumerate(zip(t0, t1, n0, n1)):
        es[f].append((i, g, a, b))
        es[g].append((i, f, b, a))

    for f0 in range(n):
        if seen[f0]:
            continue
        f, i, x = f0, -1, [[0, INF], [INF, INF]]
        while True:
            seen[f] = True
            j, g, a, b = [e for e in es[f] if e[0] != i][0]
            A, B, y, s = max(a, b), min(a, b), [[INF, INF], [INF, INF]], f == f0
            for p0 in range(2):
                for pf in range(2):
                    c = x[p0][pf]
                    if pf or s:
                        y[p0][0] = min(y[p0][0], c)
                    if A == a:
                        y[p0 or s][0] = min(y[p0 or s][0], c + B + 1)
                    elif pf or s:
                        y[p0][1] = min(y[p0][1], c + B + 1)
                    y[p0 or s][1] = min(y[p0 or s][1], c + A + 1)
            f, i, x = g, j, y
            if f == f0:
                break
        ans += min(x[1][0], x[1][1], x[0][1])
    return ans

class CandyCollection(object):
    solve = solve
