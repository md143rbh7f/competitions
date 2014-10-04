def f(_, xs, ys):
    n = len(xs)
    bad = {i for i in range(n) if xs[i] > ys[i]}

    def get(zs):
        return sorted(zs[i] for i in bad)

    def work():
        for x, y in reversed(zip(get(xs), get(ys))):
            if x > y:
                bad.add(min((xs[i], i) for i in range(n) if i not in bad and x <= ys[i])[1])
                return True
        return False

    try:
        while work(): pass
    except:
        return -1

    return len(bad)

class StoryFromTCO(object):
    minimumChanges = f
