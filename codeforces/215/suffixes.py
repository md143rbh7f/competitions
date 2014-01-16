n, m = list(map(int, input().split(' ')))

a = list(map(int, input().split(' ')))
nums = set()
for i in range(n - 1, -1, -1):
    nums.add(a[i])
    a[i] = len(nums)

while m:
    print(a[int(input()) - 1])
    m -= 1
