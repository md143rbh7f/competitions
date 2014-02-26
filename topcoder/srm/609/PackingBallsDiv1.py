class PackingBallsDiv1(object):
    def minPacks(self, k, a, b, c, d):
        x = []
        x.append(a)
        for i in range(k - 1):
            x.append((x[i] * b + c) % d + 1)
        s = 0
        for i in range(k):
            s += x[i] // k
            x[i] %= k
        x.sort(reverse=True)
        return s + min(i + x[i] for i in range(k))
