import java.math.*;
import java.util.*;

public class SlimeXGrandSlimeAuto
{
	static int INF = 123456789;

	public int travel(int[] cars, int[] districts, String[] roads, int walk, int drive)
	{
		int m = roads.length, dist[][] = new int[m][m];
		for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
		{
			char c = roads[i].charAt(j);
			int d = i == j ? 0 : INF;
			if(c >= '0' && c <= '9') d = c - '0' + 1;
			else if(c >= 'a' && c <= 'z') d = c - 'a' + 11;
			else if(c >= 'A' && c <= 'Z') d = c - 'A' + 37;
			dist[i][j] = d;
		}
		for(int k = 0; k < m; k++)
		for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

		int n0 = districts.length, n1 = cars.length, s = 0;
		n = n0 + n1 + 3;
		g = (ArrayList<Edge>[])(new ArrayList[n]);
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Edge>();
		for(int i = 0; i < n0; i++)
		{
			addEdge(n - 2, i, 1, 0);
			int t = districts[i];
			for(int j = 0; j < n1; j++)
				addEdge(i, j + n0, 1, walk * dist[s][cars[j]] + drive * dist[cars[j]][t]);
			addEdge(i, n - 3, 1, walk * dist[s][t]);
			s = t;
		}
		for(int j = 0; j < n1; j++) addEdge(j + n0, n - 1, 1, 0);
		addEdge(n - 3, n - 1, INF, 0);

		return minCostMaxFlow(n - 2, n - 1)[0];
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
