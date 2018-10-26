/*
	Java implementation of min-cost max flow using Bellman-Ford.
*/

	ArrayList<Edge>[] g;
	int n;

	class Edge
	{
		int j, ca, co, f;
		Edge r;

		Edge(int j, int ca, int co)
		{
			this.j = j;
			this.ca = ca;
			this.co = co;
		}
	}

	void addEdge(int i, int j, int ca, int co)
	{
		Edge e = new Edge(j, ca, co), f = new Edge(i, 0, -co);
		e.r = f;
		f.r = e;
		g[i].add(e);
		g[j].add(f);
	}

	int[] minCostMaxFlow(int s, int t)
	{
		int mc = 0, mf = 0, dist[] = new int[n];
		Edge[] pre = new Edge[n];
		while(true)
		{
			Arrays.fill(dist, INF);
			Arrays.fill(pre, null);
			dist[s] = 0;
			for(int q = 0; q < n; q++)
			{
				boolean change = false;
				for(int i = 0; i < n; i++) for(Edge e : g[i])
				if(e.f < e.ca && dist[i] + e.co < dist[e.j])
				{
					dist[e.j] = dist[i] + e.co;
					pre[e.j] = e;
					change = true;
				}
				if(!change) break;
			}
			if(pre[t] == null) break;
			int f = INF;
			for(Edge e = pre[t]; e != null; e = pre[e.r.j])
				f = Math.min(f, e.ca - e.f);
			for(Edge e = pre[t]; e != null; e = pre[e.r.j])
			{
				e.f += f;
				e.r.f -= f;
			}
			mf += f;
			mc += f * dist[t];
		}
		return new int[]{mc, mf};
	}
