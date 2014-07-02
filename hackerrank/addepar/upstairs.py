n = int(input())
x = [int(i) for i in input().split()]
diff = lambda i: x[i] - x[i - 1] if i > 0 and i < n and x[i] > x[i - 1] else 0
best, best_cost = -1, 0
for i in range(n - 1):
    a = diff(i) + diff(i + 1) + diff(i + 2)
    x[i], x[i + 1] = x[i + 1], x[i]
    b = diff(i) + diff(i + 1) + diff(i + 2)
    x[i], x[i + 1] = x[i + 1], x[i]
    if b - a < best_cost:
        best, best_cost = i + 1, b - a
print(best)
