class Egalitarianism(object):
    def maxDifference(self, g, d):
        inf = 1234567890
        g = [[1 if x == 'Y' else inf for x in h] for h in g]
        n = len(g)
        for i in range(n):
            g[i][i] = 0
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j])
        ans = max(max(h) for h in g)
        return ans * d if ans < inf else -1
