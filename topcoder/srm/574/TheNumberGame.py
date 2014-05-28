class TheNumberGame(object):
    def determineOutcome(self, a, b):
        a, b = str(a), str(b)
        return "Manao wins" if a.find(b) != -1 or a.find(b[::-1]) != -1 else "Manao loses"
