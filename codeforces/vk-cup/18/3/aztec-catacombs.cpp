#include <algorithm>
#include <cstdio>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int N = 300005;

vi g[N];
int q[N], p[N], d[N];

vector<vi> bfs(int x, int l) {
	vector<vi> s{{x}};
	p[x] = -1, d[x] = 0;
	rep (_, l) {
		vi nxt;
		for (auto u : s.back()) for (auto v : g[u]) if (!p[v]) {
			p[v] = u, d[v] = d[u] + 1;
			nxt.push_back(v);
		}
		s.push_back(move(nxt));
	}
	return s;
}

bool by_deg(int i, int j) {
	return g[i].size() < g[j].size();
}

vi work() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	rep (_, m) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b), g[b].push_back(a);
	}

	vector<vi> s = move(bfs(1, 3));
	if (d[n] == 1) return {n};
	if (d[n] == 2) return {p[n], n};
	if (d[n] == 3) return {p[p[n]], p[n], n};
	if (!s[2].empty()) return {p[s[2][0]], s[2][0], 1, n};

	for (auto u : s[1]) {
		p[u] = 0;
		vi h;
		for (auto v : g[u]) if (d[v] == 1) h.push_back(v);
		g[u] = move(h);
	}
	sort(all(s[1]), &by_deg);
	for (auto u : s[1]) if (!p[u]) {
		vector<vi> t = move(bfs(u, 2));
		if (!t[2].empty()) return {u, p[t[2][0]], t[2][0], u, n};
	}

	return {};
}

int main() {
	vi ans = move(work());
	if (ans.empty()) printf("-1\n");
	else {
		printf("%d\n1", ans.size());
		for (auto v : ans) printf(" %d", v);
		printf("\n");
	}
	return 0;
}
