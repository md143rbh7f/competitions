def memo(f):
    m = {}
    return lambda *a: m[a] if a in m else m.setdefault(a, f(*a))


fib = [1, 2]
while fib[-1] + fib[-2] <= 1e15:
    fib.append(fib[-1] + fib[-2])


@memo
def h(n):
    if n == 1:
        return 0
    if n == 2:
        return 1
    i, x = max((i, x) for i, x in enumerate(fib) if x < n)
    return (((n - x) % 2) << i) ^ h(n - x) ^ h(x)


class FibonacciXor(object):
    def find(self, a, b):
        return (h(b + 1) ^ h(a)) % 1000000007
