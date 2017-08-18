n, ans = int(input()) + 1, 1
d, least = [0] * n, [0] * n
d[1] = 1
seen = set()
for i in range(2, n):
    if least[i] == 0:
        least[i] = i
        for j in range(i * i, n, i):
            least[j] = i
    j, c = i, 0
    while (j % least[i]) == 0:
        j //= least[i]
        c += 1
    d[i] = (c + 1) * d[j]
    if d[i] not in seen:
        seen.add(d[i])
        ans += i
print(ans)
