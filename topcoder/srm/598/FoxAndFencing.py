class FoxAndFencing(object):
    def WhoCanWin(self, m0, m1, r0, r1, d):
        if m0 + r0 >= d:
            return 'Ciel'
        if m1 + r1 >= m0 + d:
            return 'Liss'
        if m0 > m1 and m0 + r0 > 2 * m1 + r1:
            return 'Ciel'
        if m1 > m0 and m1 + r1 > 2 * m0 + r0:
            return 'Liss'
        return "Draw"
