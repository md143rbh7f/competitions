class FoxAndFencingEasy(object):
    def WhoCanWin(self, m0, m1, d):
        if m0 >= d or m0 > 2 * m1:
            return 'Ciel'
        if m1 > 2 * m0:
            return 'Liss'
        return 'Draw'
