read_line = lambda: [int(i) for i in input().split()]
x0, y0 = read_line()
x1, y1 = read_line()
print(sum((a * x0 + b * y0 + c) * (a * x1 + b * y1 + c) < 0 for a, b, c in (read_line() for i in range(int(input())))))
