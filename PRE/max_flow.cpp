/*
	C++ implementations of Ford-Fulkerson and Edmonds-Karp.
*/

vi g[N];
int cap[N][N];
int flow[N][N];

// Edmonds-Karp
int pre[N];

int bfs(int s, int t)
{
	list<int> q;
	pre[s] = -2;
	q.push_back(s);
	while(!q.empty())
	{
		int i = *q.begin();
		q.pop_front();
		for(auto j : g[i]) if(cap[i][j] > flow[i][j] && pre[j] == -1)
			pre[j] = i, q.push_back(j);
	}
	if(pre[t] == -1) return 0;
	int ans = cap[pre[t]][t] - flow[pre[t]][t];
	for(int v = t; pre[v] >= 0; v = pre[v])
		ans = min(ans, cap[pre[v]][v] - flow[pre[v]][v]);
	for(int v = t; pre[v] >= 0; v = pre[v])
		flow[pre[v]][v] += ans, flow[v][pre[v]] -= ans;
	return ans;
}

// Ford-Fulkerson
bool seen[N];

int dfs(int s, int t, int minf)
{
	if(s == t) return minf;
	if(seen[s]) return 0;
	seen[s] = true;
	for(auto i : g[s])
	{
		if(cap[s][i] == flow[s][i]) continue;
		int minf2 = min(minf, cap[s][i] - flow[s][i]);
		minf2 = min(minf2, dfs(i, t, minf2));
		if(minf2)
		{
			flow[s][i] += minf2, flow[i][s] -= minf2;
			return minf2;
		}
	}
	return 0;
}

void add_edge(int i, int j, int c = 1)
{
	g[i].push_back(j), g[j].push_back(i), cap[i][j] = c;
}

int max_flow(int s, int t)
{
	clr(f);
	do rep(i,n) pre[i] = -1;
	while(bfs(s, t));
	//do clr(seen);
	//while(dfs(s, t, INF));
	int ans = 0;
	rep(i,n) ans += flow[s][i];
	return ans;
}
