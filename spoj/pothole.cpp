#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

template <int V, typename T = int>
struct MaxFlowGraph {
T inf = numeric_limits<T>::max();

void add_edge(int i, int j, T c = 1) {
	Edge *e0 = new Edge{j, c, 0, nullptr}, *e1 = new Edge{i, 0, 0, nullptr};
	e0->r = e1, e1->r = e0;
	g[i].push_back(e0), g[j].push_back(e1);
}

T max_flow(int s, int t) {
	T ans = 0;
	while (bfs(s, t)) {
		rep (i, V) p[i] = g[i].begin();
		ans += dfs(s, t, inf);
	}
	return ans;
}

private:
struct Edge { int j; T c, f; Edge *r; };

vector<Edge*> g[V];
int q0[V], d[V];
typename vector<Edge*>::iterator p[V];

bool bfs(int s, int t) {
	clr1(d);
	d[q0[0] = s] = 0;
	for (int *i = q0, *q1 = q0 + 1; i < q1; i++)
	for (auto e : g[*i]) if (e->c > e->f && d[e->j] == -1)
		d[e->j] = d[*i] + 1, *(q1++) = e->j;
	return d[t] > -1;
}

T dfs(int i, int t, T f) {
	if (i == t) return f;
	T ans = 0;
	for (; p[i] != g[i].end(); p[i]++) {
		Edge *e = *p[i];
		if (e->c == e->f || d[e->j] != d[i] + 1) continue;
		T f2 = dfs(e->j, t, min(f, e->c - e->f));
		e->f += f2, e->r->f -= f2;
		ans += f2, f -= f2;
		if (!f) break;
	}
	return ans;
}
};

constexpr int N = 205;

MaxFlowGraph<N> g;

int work() {
	int n, m, j;
	scanf("%d", &n);
	rep (i, n - 1) {
		scanf("%d", &m);
		rep (_, m) {
			scanf("%d", &j);
			g.add_edge(i, j - 1, i == 0 || j == n ? 1 : g.inf);
		}
	}

	int ans = g.max_flow(0, n - 1);
	g = {};
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) printf("%d\n", work());
	return 0;
}
