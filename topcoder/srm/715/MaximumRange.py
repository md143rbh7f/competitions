class MaximumRange(object):
    def findMax(self, s):
        k = sum(1 for c in s if c == '+')
        return max(k, len(s) - k)
