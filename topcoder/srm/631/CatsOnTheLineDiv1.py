INF = float('inf')

def getNumber(self, xs, ys, time):
    hi, lo, ans = -INF, -INF, 0
    for x, y in sorted(zip(xs, ys)):
        if x - time <= hi + time:
            continue
        l, r = max(x - time, lo), x + time
        if r - l + 1 >= y:
            lo = l + y
        else:
            hi = x
            ans += 1
    return ans

class CatsOnTheLineDiv1(object):
    getNumber = getNumber
