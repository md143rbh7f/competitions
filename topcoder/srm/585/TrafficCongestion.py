class TrafficCongestion(object):
    def theMinCars(self, n):
        ans = 1
        for i in range(n):
            ans = (2 * (ans + i % 2) - 1) % 1000000007
        return ans
