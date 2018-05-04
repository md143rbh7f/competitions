def work(n, k, b):
    lo, hi = (b + 1) * b // 2, b * (2 * k - b + 1) // 2
    if not (lo <= n <= hi):
        yield -1
        return

    while b:
        m = min(k, n - b * (b - 1) // 2)
        n -= m
        k = m - 1
        b -= 1
        yield m


for _ in range(int(input())):
    n, k, b = map(int, input().split())
    print(' '.join(map(str, work(n, k, b))))
