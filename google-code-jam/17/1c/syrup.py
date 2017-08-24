import math


ints = lambda: list(map(int, input().split()))

for t in range(int(input())):
    n, k = ints()
    sbs = list(reversed(sorted(
        (2 * r * h, r * r)
        for r, h in (ints() for _ in range(n)
    ))))
    ans = math.pi * max(
        s0 + b0 + sum([s for j, (s, b) in enumerate(sbs) if j != i][:k - 1])
        for i, (s0, b0) in enumerate(sbs)
    )
    print('Case #{}: {:.7f}'.format(t + 1, ans))
