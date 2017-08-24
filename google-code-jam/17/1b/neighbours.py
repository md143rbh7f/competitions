P, S = 'RYB', 'GVO'
BAD = 'IMPOSSIBLE'


def work(p, s):
    d = sum(c > 0 for c in p + s)

    for i in range(3):
        if s[i]:
            if d == 2:
                return s[i] * (P[i] + S[i]) if p[i] == s[i] else BAD
            if p[i] <= s[i]:
                return BAD
            p[i] -= s[i]

    for i in range(3):
        if p[i] > p[(i + 1) % 3] + p[(i + 2) % 3]:
            return BAD

    buf, i = max(p) * [''], 0
    for cnt, col in reversed(sorted(zip(p, P))):
        for _ in range(cnt):
            buf[i] += col
            i = (i + 1) % len(buf)
    ans = ''.join(buf)

    for i in range(3):
        ans = ans.replace(P[i], s[i] * (P[i] + S[i]) + P[i], 1)

    return ans


for i in range(int(input())):
    r, o, y, g, b, v = list(map(int, input().split()))[1:]
    p, s = [r, y, b], [g, v, o]
    print('Case #{}: {}'.format(i + 1, work(p, s)))
