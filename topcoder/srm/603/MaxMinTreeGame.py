class MaxMinTreeGame(object):
    def findend(self, e, c):
        n = len(c)
        deg = [0] * n
        for a, b in zip(range(n - 1), e):
            deg[a+1] += 1
            deg[b] += 1
        return max(c[i] for i in range(n) if deg[i] == 1)
