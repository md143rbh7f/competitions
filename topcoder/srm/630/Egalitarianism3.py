from collections import *

INF = float('inf')

def maxCities(self, n, xs, ys, ds):
    if n <3:
        return n

    dist = [[INF] * n for i in range(n)]
    for i in range(n):
        dist[i][i] = 0

    for x, y, d in zip(xs, ys, ds):
        dist[x - 1][y - 1] = dist[y - 1][x - 1] = d

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    ans = 2
    for c in range(n):
        rs = defaultdict(list)
        for i in range(n):
            js = rs[dist[c][i]]
            if all(dist[j][i] == 2 * dist[c][i] for j in js):
                js.append(i)
            ans = max(ans, len(js))

    return ans

class Egalitarianism3(object):
    maxCities = maxCities
