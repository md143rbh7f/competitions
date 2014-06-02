import java.io.*;
import java.math.*;
import java.util.*;

public class KingOfTheNorth
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	static int INF = 1000000000;

	public static void main(String[] args)
	{
		new KingOfTheNorth().run();
	}

	int inNode(int i, int j)
	{
		return 2 * (i * c + j);
	}

	int outNode(int i, int j)
	{
		return 2 * (i * c + j) + 1;
	}

	void run()
	{
		r = in.nextInt();
		c = in.nextInt();
		n = 2 * r * c + 2;
		g = (ArrayList<Edge>[])(new ArrayList[n]);
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Edge>();
		for(int i = 0; i < r; i++) for(int j = 0; j < c; j++)
		{
			addEdge(inNode(i, j), outNode(i, j), in.nextInt());
			for(int d = 0; d < 4; d++)
			{
				int ii = i + dx[d], jj = j + dy[d];
				addEdge(
					outNode(i, j),
					ii < 0 || ii >= r || jj < 0 || jj >= c ? n - 1 : inNode(ii, jj),
					INF
				);
			}
		}
		addEdge(n - 2, inNode(in.nextInt(), in.nextInt()), INF);
		System.out.println(maxFlow(n - 2, n - 1));
	}

	ArrayList<Edge>[] g;
	int n, r, c;

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

	void addEdge(int i, int j, int c)
	{
		if(c == 0) return;
		Edge e = new Edge(j, c), f = new Edge(i, 0);
		e.r = f;
		f.r = e;
		g[i].add(e);
		g[j].add(f);
	}

	int maxFlow(int s, int t)
	{
		pre = new Edge[n];
		do Arrays.fill(pre, null);
		while(maxFlowBFS(s, t) > 0);
		int ans = 0;
		for(Edge e : g[s]) ans += e.f;
		return ans;
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
		int f = INF;
		for(Edge e = pre[t]; e != null; e = pre[e.r.j])
			f = Math.min(f, e.c - e.f);
		for(Edge e = pre[t]; e != null; e = pre[e.r.j])
		{
			e.f += f;
			e.r.f -= f;
		}
		return f;
	}
}
