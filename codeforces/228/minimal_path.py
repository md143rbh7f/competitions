n, m, cnt = int(input()), 148, 0
ans = [['N'] * m for i in range(m)]

def edge(i, j):
    ans[i][j] = ans[j][i] = 'Y'

def node(*adj):
    global cnt
    i = cnt
    cnt += 1
    for j in adj:
        edge(i, j)
    return i

start, end, choice = node(), node(), node()
if n&1:
    edge(choice, end)
for i in range(1, 30):
    end, choice = node(node(end), node(end)), node(node(choice))
    if n&(1<<i):
        edge(choice, end)
edge(start, choice)

print(m)
for line in ans:
    print(''.join(line))
