from collections import *
from fractions import *
import heapq
from itertools import *
from math import *
#from functools import *
import sys
## if t!

read_line = lambda: [int(i) for i in input().split()]
## endif
INF = float('inf')

sys.setrecursionlimit(1000)

def memo(f):
    m = {}
    return lambda *a: m[a] if a in m else m.setdefault(a, f(*a))

## if t
class $NAME(object):
    def @(self, ):
## endif
