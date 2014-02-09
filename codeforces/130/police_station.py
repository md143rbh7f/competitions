read_line = lambda: map(int, input().split(' '))

n, m = read_line()

g = [[] for i in range(n)]
while m:
    a, b = map(lambda x: x - 1, read_line())
    g[a].append(b)
    g[b].append(a)
    m -= 1

def bfs(v0):
    q = [v0]
    d = [-1] * n
    d[v0] = 0
    ways = [0] * n
    ways[v0] = 1
    i = 0
    while i < len(q):
        v = q[i]
        for w in g[v]:
            if d[w] == -1:
                d[w] = d[v] + 1
                q.append(w)
            if d[w] == d[v] + 1:
                ways[w] += ways[v]
        i += 1
    return d, ways

d0, ways0 = bfs(0)
d1, ways1 = bfs(n - 1)

min_dist = d0[n - 1]
num_paths = ways0[n - 1]
ans = num_paths
for v in range(1, n - 1):
    if d0[v] + d1[v] == min_dist:
        ans = max(ans, 2 * ways0[v] * ways1[v])
print('{:.7f}'.format(ans / num_paths))
