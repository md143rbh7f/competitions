from itertools import *
from statistics import *
from math import *

t = lambda a: zip(*a)
rle = lambda s: t((k, len(list(g))) for k, g in groupby(s))

def work():
    n = int(input())
    ps, qs = t(rle(input()) for i in range(n))
    for i in range(n):
        if ps[i] != ps[0]:
            return 'Fegla Won'
    ans = 0
    for q in t(qs):
        med = median_low(q)
        ans += sum(abs(r - med) for r in q)
    return ans

for i in range(int(input())):
    print('Case #{0}:'.format(i + 1), work())
