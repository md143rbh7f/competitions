from itertools import *

def ok(xs):
    cur = []
    for k, g in groupby(xs, key=lambda x: x[0]):
        _, ls, rs = zip(*g)
        a, b, c, d = min(ls), max(rs), max(ls), min(rs)
        if c > d or any(l <= c and d <= r for l, r in cur):
            return False

        cur = sorted(cur + [[a, b]])
        nxt = cur[:1]
        for l, r in cur:
            if l > nxt[-1][1] + 1:
                nxt.append([l, r])
            else:
                nxt[-1][1] = max(nxt[-1][1], r)
        cur = nxt

        if sum(r - l + 1 for l, r in cur) > k:
            return False

    return True
    

class InverseRMQ(object):
    def possible(self, n, a, b, c):
        return 'Possible' if ok(sorted(zip(c, a, b))) else 'Impossible'
