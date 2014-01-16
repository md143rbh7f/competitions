read_line = lambda: list(map(int, input().split(' ')))
n, k = read_line()
x = read_line()
for i in range(n - 2, -1, -1):
    x[i] += x[i+1]
for i in range(n - k):
    x[i] -= x[i+k]
j = b = n - k
a = b - k
for i in range(a - 1, -1, -1):
    if x[i + k] >= x[j]:
        j = i + k
    if x[i] + x[j] >= x[a] + x[b]:
        a, b = i, j
print(a + 1, b + 1)
