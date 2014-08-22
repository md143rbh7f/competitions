INF = float('inf')

def work(a, b, x):
    can = []
    for p, q in x:
        if q > a:
            can.append(p)
        elif p > a:
            can.append(q)
    can.sort(reverse=True)
    tot = 0
    for i, j in enumerate(can):
        tot += j
        if tot >= b:
            return i + 1
    return INF

class RectangleCovering(object):
    def minimumNumber(self, a, b, h, w):
        x = [(max(p, q), min(p, q)) for p, q in zip(h, w)]
        ans = min(work(a, b, x), work(b, a, x))
        return ans if ans != INF else -1
