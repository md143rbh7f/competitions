read_ints = lambda: [int(i) for i in input().split()]
read_strs = lambda: sorted(int(s, 2) for s in input().split())

def solve():
    n, l = read_ints()
    xs = read_strs()
    ys = read_strs()
    return min((
        bin(m).count('1') for m in [xs[0] ^ ys[i] for i in range(n)]
        if sorted(x ^ m for x in xs) == ys
    ), default='NOT POSSIBLE')

t = read_ints()[0]
for i in range(t):
    print('Case #{0}: {1}'.format(i + 1, solve()))
