/*
	C++ implementations of Ford-Fulkerson and Edmonds-Karp.
*/

struct Edge
{
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[N];
int n;

void add_Edge(int i, int j, int c = 1)
{
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

// Edmonds-Karp
Edge* pre[N];

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
	int f = INF;
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}

// Ford-Fulkerson
bool seen[N];

int dfs(int s, int t, int mf)
{
	if(s == t) return mf;
	if(seen[s]) return 0;
	seen[s] = true;
	for(auto e : g[s]) if(e->c > e->f)
	{
		int mf2 = min(mf, e->c - e->f);
		mf2 = min(mf2, dfs(e->j, t, mf2));
		if(mf2)
		{
			e->f += mf2, e->r->f -= mf2;
			return mf2;
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	while(bfs(s, t)) clr(pre);
	// while(dfs(s, t, INF)) clr(seen);
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}
