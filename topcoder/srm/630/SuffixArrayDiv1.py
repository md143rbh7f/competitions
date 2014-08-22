def minimalCharacters(self, s):
    n = len(s)
    t = [0] * n + [-1]
    for i in range(n):
        t[s[i]] = i

    es = []
    for i in range(n):
        for j in range(i + 1, n):
            es.append((s[i], s[j], -1 * (t[s[i] + 1] > t[s[j] + 1])))

    x = [0] * n
    for t in range(n):
        for u, v, d in es:
            x[v] = min(x[v], x[u] + d)

    return max(x) - min(x) + 1

class SuffixArrayDiv1(object):
    minimalCharacters = minimalCharacters
