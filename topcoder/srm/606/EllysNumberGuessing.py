class EllysNumberGuessing(object):
    def getNumber(self, guess, answer):
        ok = filter(
            lambda x: 1 <= x <= 1000000000,
            reduce(
                set.intersection,
                [{g + a, g - a} for g, a in zip(guess, answer)]
            )
        )
        return -1 if len(ok) > 1 else ok[0] if len(ok) == 1 else -2
