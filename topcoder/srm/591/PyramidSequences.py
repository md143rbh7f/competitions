from fractions import *

class PyramidSequences(object):
	def distinctPairs(self, n, m):
		g = gcd(n - 1, m - 1)
		an, am = [(x - 1) / g for x in n, m]
		bn, bm = [x / 2 + 1 for x in [an, am]]
		cn, cm = [x / 2 + (x % 2) for x in [an, am]]
		return (g - 1) * an * am + bn * bm + cn * cm
