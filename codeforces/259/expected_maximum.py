m, n = map(int, input().split())
print("{:.9}".format(m - sum((i / m) ** n for i in range(m))))
