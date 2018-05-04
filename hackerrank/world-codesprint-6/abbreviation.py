for t in range(int(input())):
    a, b = input(), input()
    n, m = len(a), len(b)
    ans = [[None for j in range(m + 1)] for i in range(n + 1)]

    def work(i, j):
        if i == n and j == m:
            return True
        c, d = a[i] if i < n else '$A', b[j] if j < m else '$B'
        match = c.upper() == d.upper() and ans[i + 1][j + 1]
        drop_c = c.islower() and ans[i + 1][j]
        drop_d = d.islower() and ans[i][j + 1]
        return match or drop_c or drop_d

    for i in range(n, -1, -1):
        for j in range(m, -1, -1):
            ans[i][j] = work(i, j)
        
    print('YES' if ans[0][0] else 'NO')
