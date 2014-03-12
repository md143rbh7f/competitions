from collections import *

class EmoticonsDiv1(object):
    def printSmiles(self, x):
        d, q = {(1, 0): 0}, deque([(1, 0)])
        while q:
            i, j = q.popleft()
            if i == x:
                return d[(i, j)]
            for s in [(i + j, j), (i, i), (i - 1, j)]:
                if s not in d:
                    d[s] = d[(i, j)] + 1
                    q.append(s)
