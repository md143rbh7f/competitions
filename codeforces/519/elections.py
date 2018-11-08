n = int(input())
xs = list(map(int, input().split()))
max_x = max(xs)
bad = sum(xs)
good = n * max_x - bad
print(max_x + max(0, 1 + (bad - good) // n))
