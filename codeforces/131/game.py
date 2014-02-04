from collections import *

read_line = lambda: [int(i) for i in input().split(' ')]

n = read_line()[0]
cs = [c - 1 for c in read_line()]
g = [[] for v in range(n)]
parent_cnt = [0] * n
for v in range(n):
    parents = read_line()
    parent_cnt[v] = len(parents) - 1
    for i in range(1, len(parents)):
        g[parents[i] - 1].append(v)

def work(x):
    pcnt = list(parent_cnt)
    qs = [
        deque(v for v in range(n) if cs[v] == c and pcnt[v] == 0)
        for c in range(3)
    ]
    ans = 0
    while True:
        while qs[x]:
            v = qs[x].popleft()
            ans += 1
            for w in g[v]:
                pcnt[w] -= 1
                if pcnt[w] == 0:
                    qs[cs[w]].append(w)
        if qs[0] or qs[1] or qs[2]:
            ans += 1
            x = (x + 1) % 3
        else:
            break
    return ans

print(min(work(i) for i in range(3)))
