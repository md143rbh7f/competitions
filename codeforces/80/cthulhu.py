read_line = lambda: [int(i) for i in input().split(' ')]

n, m = read_line()
g = [[] for i in range(n)]
for i in range(m):
    a, b = [v - 1 for v in read_line()]
    g[a].append(b)
    g[b].append(a)

seen = [False] * n
def dfs(v):
    if seen[v]:
        return 0
    seen[v], cnt = True, 1
    for u in g[v]:
        cnt += dfs(u)
    return cnt

print("FHTAGN!" if n == m == dfs(0) else "NO")
