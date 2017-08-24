for i in range(int(input())):
    d, n = map(int, input().split())
    xvs = [tuple(map(int, input().split())) for _ in range(n)]
    print('Case #{}: {:.7f}'.format(i + 1, d / max((d - xv[0]) / xv[1] for xv in xvs)))
