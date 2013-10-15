import java.math.*;
import java.util.*;

public class FoxAndGo3
{
	int x, y, n, m, INF = 12345;
	int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	ArrayList<Edge>[] g;
	boolean[] seen;

	int id(int i, int j)
	{
		return i * y + j;
	}

	public int maxEmptyCells(String[] b)
	{
		x = b.length;
		y = b[0].length();
		n = x * y + 2;
		g = new ArrayList[n];
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Edge>();
		seen = new boolean[n];
		int m = 0;
		for(int i = 0; i < x; i++) for(int j = 0; j < y; j++)
		switch(b[i].charAt(j))
		{
			case '.':
				addEdge(id(i, j), n - 1, 1);
				m++;
				break;
			case 'o':
				addEdge(n - 2, id(i, j), 1);
				m++;
				for(int d = 0; d < 4; d++)
				{
					int ii = i + dx[d], jj = j + dy[d];
					if(ii >= 0 && ii < x && jj >= 0 && jj < y
						&& b[ii].charAt(jj) == '.')
						addEdge(id(i, j), id(ii, jj), INF);
				}
				break;
			default:
				break;
		}
		return m - maxFlow(n - 2, n - 1);
	}

	void addEdge(int i, int j, int c)
	{
		Edge e = new Edge(j, c), f = new Edge(i, 0);
		e.r = f;
		f.r = e;
		g[i].add(e);
		g[j].add(f);
	}

	class Edge
	{
		int j, c, f;
		Edge r;

		Edge(int j, int c)
		{
			this.j = j;
			this.c = c;
		}
	}

	int maxFlow(int s, int t)
	{
		do Arrays.fill(seen, false);
		while(maxFlowDFS(s, t, INF) > 0);
		int ans = 0;
		for(Edge e : g[s]) ans += e.f;
		return ans;
	}

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
}
