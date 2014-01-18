n = int(input())
m = 2 * n + 1

pos = set([(0, 0)])
for i in range(n):
    t, w = list(map(int, input().split(' ')))
    next_pos = set()
    for a, b in pos:
        if a + t <= m:
            next_pos.add((a + t, b))
        if b + w <= m:
            next_pos.add((a, b + w))
    pos = next_pos

print(min(t for t, w in pos if t >= w))
