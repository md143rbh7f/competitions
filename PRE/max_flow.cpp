/*
	C++ implementations of Ford-Fulkerson and Edmonds-Karp.
*/

struct edge
{
	int j, c, f;
	edge * r;
};

vector<edge*> g[N];
int n;

void add_edge(int i, int j, int c = 1)
{
	edge* e = new edge{j, c, 0, 0}, *f = new edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

// Edmonds-Karp
edge* pre[N];

int bfs(int s, int t)
{
	list<int> q;
	q.push_back(s);
	while(!q.empty())
	{
		int i = *q.begin();
		q.pop_front();
		for(auto e : g[i]) if(e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push_back(e->j);
	}
	if(!pre[t]) return 0;
	int ans = INF;
	for(int v = t; pre[v]; v = pre[v]->r->j)
		ans = min(ans, pre[v]->c - pre[v]->f);
	for(int v = t; pre[v]; v = pre[v]->r->j)
		pre[v]->f += ans, pre[v]->r->f -= ans;
	return ans;
}

// Ford-Fulkerson
bool seen[N];

int dfs(int s, int t, int minf)
{
	if(s == t) return minf;
	if(seen[s]) return 0;
	seen[s] = true;
	for(auto e : g[s]) if(e->c > e->f)
	{
		int minf2 = min(minf, e->c - e->f);
		minf2 = min(minf2, dfs(e->j, t, minf2));
		if(minf2)
		{
			e->f += minf2, e->r->f -= minf2;
			return minf2;
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	do clr(pre);
	while(bfs(s, t));
	/*
	do clr(seen);
	while(dfs(s, t, INF));
	*/
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}
