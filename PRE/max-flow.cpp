/*
 * Implementation of Dinitz's algorithm for computing the max flow through a
 * graph.
 */

template <int V, int E, typename T>
struct MaxFlowGraph {
T inf = numeric_limits<T>::max();

void add_edge(int i, int j, T c = 1) {
	g[i].push_back(e1); *(e1++) = {j, c, 0};
	g[j].push_back(e1); *(e1++) = {i, 0, 0};
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
struct Edge { int j; T c, f; };

Edge e0[2 * E], *e1 = e0;
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
		e->f += f2, e0[(e - e0) ^ 1].f -= f2;
		ans += f2, f -= f2;
		if (!f) break;
	}
	return ans;
}
};
