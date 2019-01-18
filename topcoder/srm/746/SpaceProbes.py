from decimal import *
getcontext().prec = 60


def sub(a, b):
    return tuple(a[i] - b[i] for i in range(3))


def cross(a, b):
    return tuple(
        a[(i + 1) % 3] * b[(i + 2) % 3] - b[(i + 1) % 3] * a[(i + 2) % 3]
        for i in range(3)
    )


def avg(a, b):
    return tuple((a[i] + b[i]) / 2 for i in range(3))


def dot(a, b):
    return sum(a[i] * b[i] for i in range(3))


class SpaceProbes(object):
    def focusDistance(self, x, y, z):
        ps = list(
            (Decimal(x[i]), Decimal(y[i]), Decimal(z[i]))
            for i in range(5)
        )
        u, v = sub(ps[1], ps[0]), sub(ps[3], ps[2])
        w = cross(u, v)
        p = sub(ps[4], avg(ps[0], ps[2]))
        if w[0] == w[1] == w[2] == 0:
            return float((dot(p, p) - dot(p, u) ** 2 / dot(u, u)).sqrt())
        return float(abs(dot(p, w)) / dot(w, w).sqrt())
