from collections import *
from itertools import *

Point = namedtuple('Point', ['x', 'y', 'u', 'v'])
is_sorted = lambda xs: all(a < b for a, b in zip(xs, xs[1:]))

class NarrowPassage(object):
    def minDist(self, l, xs, ys):
        n = len(xs) + 1
        u = dict(zip(sorted(xs), count()))
        v = dict(zip(sorted(ys), count()))
        ps = [Point(x, y, u[x], v[y]) for x, y in zip(xs, ys)]
        ys = [p.y for p in sorted(ps)]
        ans0 = min(
            sum(
                x + y if u < i else
                abs(x - y) if u < j else
                2 * l - x - y
                for x, y, u, v in ps
            )
            for i in range(n) for j in range(n)
            if is_sorted(
                [max(ys[:i] + [-1])] + ys[i:j] + [min(ys[j:] + [float('inf')])]
            )
        )
        ans1 = min(
            sum(
                l * ((u < i) ^ (v < j))
                + (x if u < i else l - x)
                + (y if v < j else l - y)
                for x, y, u, v in ps
            )
            for i in range(n) for j in range(n)
        )
        return min(ans0, ans1)
