n, m = map(int, input().split())
print('{:.9}'.format((1 + (n - 1) * (m - 1) / (n * m - 1)) / n) if n > 1 or m > 1 else 1)
