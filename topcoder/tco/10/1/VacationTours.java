import java.math.*;
import java.util.*;

public class VacationTours
{
	static int INF = 123456;

	static int dig(char c)
	{
		if(c >= 'A' && c <= 'Z') return c - 'A';
		if(c >= 'a' && c <= 'z') return c - 'a' + 26;
		if(c >= '0' && c <= '9') return c - '0' + 52;
		if(c == '+') return 62;
		return 63;
	}

	public int getIncome(String[] c, String[] d, int fee)
	{
		int m = c.length;
		n = 2 * m + 2;
		g = (ArrayList<Edge>[])(new ArrayList[n]);
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Edge>();
		for(int i = 1; i < m; i++) addEdge(2 * i, 2 * i + 1, 1, 0);
		for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) if(i != j)
			addEdge(2 * i + 1, 2 * j, 1, 64 * dig(c[i].charAt(j)) + dig(d[i].charAt(j)));
		addEdge(n - 2, 1, 0, 0);
		addEdge(0, n - 1, INF, 0);
		Edge in = g[n-2].get(0);

		int ans = 0;
		for(int t = 1; t < m; t++)
		{
			in.ca = t;
			ans = Math.max(ans, t * fee - minCostMaxFlow(n - 2, n - 1)[0]);
			for(int i = 0; i < n; i++) for(Edge e : g[i]) e.f = 0;
		}
		return ans;
	}

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
}
