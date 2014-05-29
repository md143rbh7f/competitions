fib = [1, 2]
while fib[-1] + fib[-2] <= 1e15:
    fib.append(fib[-1] + fib[-2])

mem = {1: 0, 2: 1}
def f(n):
    if n not in mem:
        i = max(i for i, x in enumerate(fib) if x < n)
        mem[n] = (((n ^ fib[i]) & 1) << i) ^ f(n - fib[i]) ^ f(fib[i])
    return mem[n]

class FibonacciXor(object):
    def find(self, a, b):
        return (f(b + 1) ^ f(a)) % 1000000007
