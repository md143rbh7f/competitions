def ok(r, i, c):
    j = 0
    for k in range(n):
        if (c if k == i else r[k]) != (c if j == i else r[j]):
            j = k
        if k - j + 1 > n / 2:
            return False
    return True

f = lambda i, c: all(ok(r, i, c) for r in g)

class TaroJiroGrid(object):
    def getNumber(self, h):
        global n, g
        n, g = len(h), zip(*h)
        return 0 if f(-1, '') else 1 if any(f(i, c) for i in range(n) for c in 'BW') else 2
