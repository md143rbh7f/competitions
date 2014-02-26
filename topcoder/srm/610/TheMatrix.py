class TheMatrix(object):
    def MaxArea(self, b):
        n, m, ans = len(b), len(b[0]), 0
        s = [0] * m
        for i in range(n):
            for j in range(m):
                h = s[j] = 1 + (i > 0 and b[i][j] != b[i-1][j]) * s[j]
                ans = max(ans, h)
                for k in range(j):
                    if b[i][j-k-1] == b[i][j-k]:
                        break
                    h = min(h, s[j-k-1])
                    ans = max(ans, h * (k + 2))
        return ans
