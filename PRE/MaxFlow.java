/*
	Java implementations of Ford-Fulkerson and Edmonds-Karp.
*/
	ArrayList<Edge>[] g;
	int n;

	class Edge
	{
		int i, j, c, f;
		Edge r;

		Edge(int i, int j, int c)
		{
			this.i = i;
			this.j = j;
			this.c = c;
		}
	}

	void addEdge(int i, int j, int c)
	{
		Edge e = new Edge(i, j, c), f = new Edge(j, i, 0);
		e.r = f;
		f.r = e;
		g[i].add(e);
		g[j].add(f);
	}

	int maxFlow(int s, int t)
	{
		/*
		do Arrays.fill(seen, false);
		while(maxFlowDFS(s, t, INF) > 0);
		*/
		do Arrays.fill(pre, null);
		while(maxFlowBFS(s, t) > 0);
		int ans = 0;
		for(Edge e : g[s]) ans += e.f;
		return ans;
	}

	// Ford-Fulkerson
	boolean[] seen;

	int maxFlowDFS(int s, int t, int minFlow)
	{
		if(s == t) return minFlow;
		if(seen[s]) return 0;
		seen[s] = true;
		for(Edge e : g[s])
		{
			if(e.c == e.f) continue;
			int minFlow2 = Math.min(minFlow, e.c - e.f);
			minFlow2 = Math.min(minFlow2, maxFlowDFS(e.j, t, minFlow2));
			if(minFlow2 > 0)
			{
				e.f += minFlow2;
				e.r.f -= minFlow2;
				return minFlow2;
			}
		}
		return 0;
	}

	// Edmonds-Karp
	Edge[] pre;

	int maxFlowBFS(int s, int t)
	{
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(s);
		while(!q.isEmpty())
		{
			int i = q.poll();
			for(Edge e : g[i]) if(e.c > e.f && e.j != s && pre[e.j] == null)
			{
				pre[e.j] = e;
				q.add(e.j);
			}
		}
		if(pre[t] == null) return 0;
		int ans = INF;
		for(int v = t; pre[v] != null; v = pre[v].r.j)
			ans = Math.min(ans, pre[v].c - pre[v].f);
		for(int v = t; pre[v] != null; v = pre[v].r.j)
		{
			pre[v].f += ans;
			pre[v].r.f -= ans;
		}
		return ans;
	}
