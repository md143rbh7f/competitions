/*
	C++ implementation of min-cost max flow using Bellman-Ford.
*/

struct Edge {
	int j, ca, co, f;
	Edge * r;
};

vector<Edge*> g[N];

void add_edge(int i, int j, int ca, int co) {
	Edge * e = new Edge{j, ca, co, 0, 0}, * f = new Edge{i, 0, -co, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

void min_cost_max_flow(int s, int t, int & mc, int & mf, int budget=-1, int lim=-1) {
	mc = mf = 0;
	int dist[n];
	Edge * pre[n];
	while (true) {
		rep (i, n) dist[i] = INF;
		dist[s] = 0;
		clr0(pre);
		rep (q, n) {
			bool change = false;
			rep (i, n) for (auto & e : g[i])
			if (e->f < e->ca && dist[i] + e->co < dist[e->j]) {
				dist[e->j] = dist[i] + e->co, pre[e->j] = e;
				change = true;
			}
			if (!change) break;
		}
		if (!pre[t]) break;

		int f = INF;
		if (lim > 0)
			f = min(f, lim);
		if (budget >= 0 && dist[t] > 0)
			f = min(f, budget / dist[t]);

		for (Edge * e = pre[t]; e; e = pre[e->r->j])
			f = min(f, e->ca - e->f);
		for (Edge * e = pre[t]; e; e = pre[e->r->j])
			e->f += f, e->r->f -= f;

		mf += f, mc += f * dist[t];

		if (lim > 0) {
			lim -= f;
			if (lim == 0) break;
		}
		if (budget >= 0) {
			budget -= f * dist[t];
			if (dist[t] > budget) break;
		}
	}
}
