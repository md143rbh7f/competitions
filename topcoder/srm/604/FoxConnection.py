class FoxConnection(object):
    def minimalDistance(self, a, b, have):
        n, tot = len(have), sum(c == 'Y' for c in have)
        g = [[] for i in range(n)]
        for x, y in zip(a, b):
            g[x - 1].append(y - 1)
            g[y - 1].append(x - 1)

        def merge(sv, cv, sw, cw):
            cx = [float('inf')] * (len(cv) + len(cw) - 1)
            cx[0] = cv[0] + cw[0]
            for i in range(1, len(cv)):
                for j in range(len(cw)):
                    cx[i + j] = min(cx[i + j], cv[i] + cw[j])
            if tot < len(cw):
                cx[tot] = min(cx[tot], cv[0] + cw[tot])
            return sv + sw, cx

        def rec(u, v):
            sv, cv = have[v] == 'Y', [0, 0]
            for w in g[v]:
                if w != u:
                    sv, cv = merge(sv, cv, *rec(v, w))
            for i in range(len(cv)):
                cv[i] += abs(i - sv)
            return sv, cv

        return rec(-1, 0)[1][tot]
