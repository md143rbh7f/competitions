/*
 * Dijkstra
 */

struct edge { int v, d; };
vector<edge> g[N];
struct by
{
	int * x;
	inline bool operator()(int a, int b) const
	{ return x[a] < x[b] || (x[a] == x[b] && a < b); }
};

void dijkstra(int n, int s, int * d)
{
	rep(i, n) d[i] = INF;
	d[s] = 0;
	set<int, by> q({s}, by{d});
	while(!q.empty())
	{
		int u = *q.begin();
		q.erase(u);
		for(auto & e : g[u]) if(d[e.v] > d[u] + e.d)
		{
			q.erase(e.v);
			d[e.v] = d[u] + e.d;
			q.insert(e.v);
		}
	}
}


/*
 * Bellman-Ford
 */

struct edge { int u, v, d; };
vector<edge> es;

void bellman_ford(int n, int s, int * d)
{
	rep(i, n) d[i] = INF;
	d[s] = 0;
	rep(t, n) for(auto & e : es)
		d[e.v] = min(d[e.v], d[e.u] + e.d);
}
