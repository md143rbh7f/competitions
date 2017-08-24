INF = float('inf')
ints = lambda: map(int, input().split())


def work():
    n, q = ints()
    rss = [tuple(ints()) for _ in range(n)]

    d0 = [[x if x >= 0 else INF for x in ints()] for _ in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d0[i][j] = min(d0[i][j], d0[i][k] + d0[k][j])

    d1 = [[d0[i][j] / rss[i][1] if d0[i][j] <= rss[i][0] else INF for j in range(n)] for i in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j])

    for _ in range(q):
        u, v = ints()
        yield d1[u - 1][v - 1]


for i in range(int(input())):
    print('Case #{}: {}'.format(i + 1, ' '.join(map(lambda x: '{:.7f}'.format(x), work()))))
