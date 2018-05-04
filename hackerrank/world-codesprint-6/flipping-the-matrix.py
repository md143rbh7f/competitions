read_line = lambda: (int(i) for i in input().split())

def work():
    n = int(input())
    ans = [[0 for j in range(n)] for i in range(n)]
    for i_ in range(2 * n):
        i = min(i_, 2 * n - 1 - i_)
        for j_, x in enumerate(read_line()):
            j = min(j_, 2 * n - 1 - j_)
            ans[i][j] = max(ans[i][j], x)
    return sum(sum(_) for _ in ans)

for t in range(int(input())):
    print(work())
