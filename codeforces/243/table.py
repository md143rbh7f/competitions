from functools import *

read_line = lambda: [int(i) for i in input().split()]

n, m, k = read_line()
a = [read_line() for i in range(n)]
if n < m:
    n, m, a = m, n, zip(*a)

xs = [reduce(lambda x, b: 2 * x + b, y) for y in a]
minm = lambda a: min(a, m - a)
work = lambda y: sum(minm(bin(x ^ y).count('1')) for x in xs)
ans = min(map(work, xs if m > k else range(1<<m)))

print(ans if ans <= k else -1)
