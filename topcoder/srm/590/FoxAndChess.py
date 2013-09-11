from itertools import *

def compress(s):
	return [(c, i) for c, i in zip(s, count()) if c != '.']

class FoxAndChess(object):
	def ableToMove(self, s0, s1):
		t0, t1 = map(compress, [s0, s1])
		if len(t0) != len(t1):
			return "Impossible"

		for (c0, i0), (c1, i1) in zip(t0, t1):
			if any([c0 != c1, c0 == 'L' and i0 < i1, c0 == 'R' and i0 > i1]):
				return "Impossible"

		return "Possible"
