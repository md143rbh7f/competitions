read_line = lambda: [int(i) for i in input().split()]
n, k = read_line()
xs = read_line()
b = int(input())
tot = sum(xs)
c = (tot - xs[k]) // 2
ans = 'Bon Appetit' if b == c else b - c
print(ans)
