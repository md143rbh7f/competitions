from collections import *

class HappyLetterDiv1(object):
    def getHappyLetters(self, cs):
        n = len(cs)
        sz = defaultdict(int)
        for c in cs:
            sz[c] += 1
        return ''.join(
            c for c in sorted(set(cs))
            if any(
                (n - m) % 2 == 0
                and all(2 * (sz[d] - (d == c) * m) <= n - m for d in cs)
                for m in range(1, sz[c] + 1)
            )
        )
