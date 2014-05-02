read_line = lambda: [int(i) for i in input().split()]
n, k = read_line()
x = read_line()
print(max(sum(sorted(x[l:r] + sorted(x[:l] + x[r:])[-k:])[l-r:]) for l in range(n) for r in range(l + 1, n + 1)))
