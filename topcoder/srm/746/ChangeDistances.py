class ChangeDistances(object):
    def findGraph(self, g):
        n = len(g)
        return tuple(
            ''.join(
                '0' if i == j or g[i][j] == '1' else '1'
                for j in range(n)
            )
            for i in range(n)
        )
