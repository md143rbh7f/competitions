class ORSolitaire(object):
	def getMinimum(self, nums, goal):
		return min(
			sum((x & goal == x) and ((x >> i) & 1) for x in nums)
			for i in range(30)
			if (goal >> i) & 1
		)
