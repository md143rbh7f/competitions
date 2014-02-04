from collections import *

read_line = lambda: [int(i) for i in input().split(' ')]

n = read_line()[0]
g, deg = [[] for i in range(n)], [0] * n
for i in range(n):
    a, b = [v - 1 for v in read_line()]
    g[a].append(b)
    g[b].append(a)
    deg[a] += 1
    deg[b] += 1

ans = [0] * n
q = deque(v for v in range(n) if deg[v] == 1)
while q:
    v = q.popleft()
    ans[v] = None
    for u in g[v]:
        deg[u] -= 1
        if deg[u] == 1:
            q.append(u)

q = deque(v for v in range(n) if ans[v] == 0)
while q:
    v = q.popleft()
    for u in g[v]:
        if ans[u] is None:
            ans[u] = ans[v] + 1
            q.append(u)

print(' '.join(str(x) for x in ans))
