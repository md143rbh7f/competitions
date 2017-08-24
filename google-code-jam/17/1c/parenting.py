import itertools


ints = lambda: tuple(map(int, input().split()))


def work():
    n, m = ints()
    ivls = sorted(itertools.chain(
        ((ints(), 0) for _ in range(n)),
        ((ints(), 1) for _ in range(m))
    ))

    ans = 0
    ts = [0, 0]
    dtss = [], []
    (a0, b0), c0 = ivls[-1]

    for (a, b), c in ivls:
        ts[c] += b - a
        if c == c0:
            dtss[c].append((1440 + a - b0) % 1440)
        else:
            ans += 1
        a0, b0, c0 = a, b, c

    for t, dts in zip(ts, map(sorted, dtss)):
        for dt in dts:
            if t + dt <= 720:
                t += dt
            else:
                ans += 2

    return ans


for t in range(int(input())):
    print('Case #{}: {}'.format(t + 1, work()))
