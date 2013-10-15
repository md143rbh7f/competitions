/*
	Java implementations of Ford-Fulkerson and Edmonds-Karp.
*/
	ArrayList<Integer>[] g;
	int[][] cap;
	int[][] flow;
	int n;

	void addEdge(int i, int j, int c)
	{
		g[i].add(j);
		g[j].add(i);
		cap[i][j] = c;
	}

	int maxFlow(int s, int t)
	{
		/*
		do Arrays.fill(seen, false);
		while(maxFlowDFS(s, t, INF) > 0);
		*/
		do Arrays.fill(prev, -1);
		while(maxFlowBFS(cap, flow, prev, s, t, INF ) > 0);
		int max = 0;
		for(int i = 0; i < n; i++) max += flow[i][t];
		return max;
	}

	// Ford-Fulkerson
	boolean[] seen;

	int maxFlowDFS(int s, int t, int minflow)
	{
		if(s == t) return minflow;
		if(seen[s]) return 0;
		seen[s] = true;
		for(int i : g[s])
		{
			if(cap[s][i] == flow[s][i]) continue;
			int minflow2 = Math.min(minflow, cap[s][i] - flow[s][i]);
			minflow2 = Math.min(minflow2, maxFlowDFS(i, t, minflow2));
			if(minflow2 > 0)
			{
				flow[s][i] += minflow2;
				flow[i][s] -= minflow2;
				return minflow2;
			}
		}
		return 0;
	}

	// Edmonds-Karp
	int[] prev;

	int maxFlowBFS(int s, int t, int minflow)
	{
		LinkedList<Integer> q = new LinkedList<Integer>();
		prev[s] = -2;
		q.add(s);
		while(!q.isEmpty())
		{
			int i = q.poll();
			for(int j = 0; j < cap.length; j++)
			if(cap[i][j] > flow[i][j] && prev[j] == -1)
			{
				prev[j] = i;
				q.add(j);
			}
		}
		if(prev[t] == -1) return 0;
		int ans = cap[prev[t]][t] - flow[prev[t]][t];
		for(int v = t; prev[v] >= 0; v = prev[v])
			ans = Math.min(ans, cap[prev[v]][v] - flow[prev[v]][v]);
		for(int v = t; prev[v] >= 0; v = prev[v])
		{
			flow[prev[v]][v] += ans;
			flow[v][prev[v]] -= ans;
		}
		return ans;
	}
