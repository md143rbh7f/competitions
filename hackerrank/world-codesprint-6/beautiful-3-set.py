n = int(input())
s = (n + 1) // 3

pts = []

x, y = 0, s
while x + y <= n:
    pts.append((x, y, n - x - y))
    x += 1
    y += 1

x, y = s + 1, 0
while x + y <= n and y < s:
    pts.append((x, y, n - x - y))
    x += 1
    y += 1

print(len(pts))
for pt in pts:
    print(' '.join(map(str, pt)))
