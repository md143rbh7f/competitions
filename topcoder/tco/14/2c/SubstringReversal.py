class SubstringReversal(object):
    def solve(self, s):
        n = len(s)
        for i in range(n):
            if min(s[i:]) != s[i]:
                return min((s[i:j+1][::-1] + s[j+1:], i, j) for j in range(i + 1, n))[1:]
        return 0, 0
