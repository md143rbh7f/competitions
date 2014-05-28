from math import *

class RadioRange(object):
    def RadiusProbability(self, xs, ys, rs, z):
        evts = [(0, 0), (z, 0)]
        for x, y, r in zip(xs, ys, rs):
            evts.append((max(hypot(x, y) - r, 0), 1))
            evts.append((min(hypot(x, y) + r, z), -1))
        evts.sort()
        ans, bad = 0, 0
        for i in range(len(evts) - 1):
            bad += evts[i][1]
            if not bad:
                ans += evts[i + 1][0] - evts[i][0]
        return ans / z
