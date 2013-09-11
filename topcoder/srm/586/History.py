class History(object):
	def verifyClaims(self, dynasties, battles, queries):
		n = len(dynasties)
		v = [[int(x) for x in dynasty.split()] for dynasty in dynasties]
		d = n * [0]
		g = []

		def add_battle(battle):
			x = ord(battle[0]) - ord('A')
			xi = int(battle[1])
			y = ord(battle[3]) - ord('A')
			yi = int(battle[4])
			g.append((x, y, v[x][xi+1] - v[y][yi] - 1))
			g.append((y, x, v[y][yi+1] - v[x][xi] - 1))

		for battle in ''.join(battles).split():
			add_battle(battle)

		def bellman_ford():
			for i in xrange(n):
				changed = False
				for a, b, e in g:
					if d[a] + e < d[b]:
						d[b] = d[a] + e
						changed = True
				if not changed:
					return True
			return False

		def get(query):
			add_battle(query)
			ok = bellman_ford()
			g.pop()
			g.pop()
			return 'Y' if ok else 'N'

		return ''.join(get(query) for query in queries)
