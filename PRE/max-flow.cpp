/*
 * Implementations of Edmonds-Karp and Ford-Fulkerson for computing the max flow
 * through a network. Uncomment the appropriate line to select an algorithm.
 */

template <int SZ, typename T, T INF>
struct MaxFlowGraph {
void add_edge(int i, int j, T c = 1) {
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

T max_flow(int s, int t) {
	// Edmonds-Karp:
	// for (clr0(pre); bfs(s, t); clr0(pre));
	// Ford-Fulkerson:
	// for (clr0(seen); dfs(s, t, INF); clr0(seen));
	T ans = 0;
	for (auto e : g[s]) ans += e->f;
	return ans;
}

private:
struct Edge {
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[SZ];

// Edmonds-Karp
Edge* pre[SZ];

T bfs(int s, int t) {
	queue<int> q({s});
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		for (auto e : g[i]) if (e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push(e->j);
	}
	if (!pre[t]) return 0;
	T f = INF;
	for (Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for (Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}

// Ford-Fulkerson
bool seen[SZ];

T dfs(int s, int t, T mf) {
	if (s == t) return mf;
	if (seen[s]) return 0;
	seen[s] = true;
	for (auto e : g[s]) if (e->c > e->f) {
		T mf2 = min(mf, e->c - e->f);
		mf2 = min(mf2, dfs(e->j, t, mf2));
		if (mf2) {
			e->f += mf2, e->r->f -= mf2;
			return mf2;
		}
	}
	return 0;
}
};
