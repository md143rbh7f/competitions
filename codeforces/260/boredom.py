N = 100005
x = [0] * N
input()
for i in map(int, input().split(' ')):
    x[i] += 1
for i in range(2, N):
    x[i] = max(x[i - 1], x[i] * i + x[i - 2])
print(x[N - 1])
