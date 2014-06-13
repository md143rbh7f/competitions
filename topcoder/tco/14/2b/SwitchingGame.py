def f(need):
    ans, last = 0, -1
    for b, a in need:
        if a > last:
            ans += 1
            last = b
    return ans

class SwitchingGame(object):
    def timeToWin(self, sts):
        sts = zip(*sts)
        n = len(sts)
        need = [[], []]
        for st in sts:
            s, last = False, -1
            for t, x in enumerate(st):
                if x != '?':
                    if (s and x == '-') or ((not s) and x == '+'):
                        need[s].append((t, last + 1))
                        s = not s
                    last = t
        return len(sts[0]) + sum(f(sorted(x)) for x in need)
