class ShoppingSurveyDiv1(object):
    def minValue(_, n, k, s):
        ans = n
        for i in range(n + 1):
            ans = min(ans, i + max(0, sum(s) - (n - i) * (k - 1)))
            s = [c - 1 for c in s if c]
        return ans
