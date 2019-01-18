class FindStringHard(object):
    def withAntipalindromicSubstrings(self, n):
        if n == 0:
            return ''
        if n == 1:
            return 'ab'
        ans, i, s = 'a', 1, 0
        while True:
            j = i + 2
            t = s + j - 1
            if t > n:
                break
            ans += 'ba'
            i, s = j, t
        if n > s:
            ans += 'a' + self.withAntipalindromicSubstrings(n - s)
        return ans
