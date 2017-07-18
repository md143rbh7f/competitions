di = [1, 0, -1, 0]
dj = [0, -1, 0, 1]
res = ['\\', '/']

def pos(a, r, c):
    if a < c:
        return 0, a, 0
    a -= c
    if a < r:
        return a, c - 1, 1
    a -= r
    if a < c:
        return r - 1, c - 1 - a, 2
    a -= c
    return r - 1 - a, 0, 3

def build(a, b, r, c, g):
    (i, j, d), end = pos(a, r, c), pos(b, r, c)
    while 0 <= i < r and 0 <= j < c:
        if g[i][j] == -1:
            g[i][j] = d & 1
        d ^= (g[i][j] ^ 1) << 1 | 1
        if (i, j, d ^ 2) == end:
            return True
        i += di[d]
        j += dj[d]
    return False
    
def solve(r, c, pairs):
    n = 2 * (r + c)
    dist = lambda p: (p[1] - p[0] + n) % n
    pairs = sorted((min((a, b), (b, a), key=dist) for a, b in pairs), key=dist)
    g = [[-1 for j in range(c)] for i in range(r)]
    return '\n'.join(''.join(res[max(0, c)] for c in r) for r in g) \
        if all(build(a, b, r, c, g) for a, b in pairs) \
        else "IMPOSSIBLE"

for i in range(int(input())):
    r, c = map(int, input().split())
    perm = list(map((lambda s: int(s) - 1), input().split()))
    pairs = zip(perm[::2], perm[1::2])
    print("Case #{}:".format(i + 1))
    print(solve(r, c, pairs))
