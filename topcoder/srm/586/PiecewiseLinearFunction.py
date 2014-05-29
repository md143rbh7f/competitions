class PiecewiseLinearFunction(object):
    def maximumSolutions(self, ys):
        n = len(ys)
        return -1 if any(ys[i] == ys[i + 1] for i in range(n - 1)) else max(
            (z == ys[0])
            + sum(ys[i] < z <= ys[i + 1] or ys[i] > z >= ys[i + 1] for i in range(n - 1))
            for z in [0.5 * (y0 + y1) for y0 in ys for y1 in ys]
        )
