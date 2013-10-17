import java.io.*;
import java.util.*;

public class Congest
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int INF = 1234567890;

	public static void main(String[] args)
	{
		new Congest().run();
	}

	public void run()
	{
		n = in.nextInt() + 1;
		int m = in.nextInt(), c = in.nextInt(), cnt[] = new int[n];
		final int[] dist = new int[n];
		g = new ArrayList[n];
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Edge>();
		while(m --> 0) addEdge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
		while(c --> 0) cnt[in.nextInt() - 1]++;

		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>(){
			public int compare(Integer a, Integer b)
			{
				if(dist[a] != dist[b]) return dist[a] - dist[b];
				return a - b;
			}
		});
		Arrays.fill(dist, INF);
		dist[0] = 0;
		q.add(0);
		while(!q.isEmpty())
		{
			int i = q.pollFirst();
			for(Edge e : g[i])
			{
				if(dist[i] + e.d < dist[e.j])
				{
					q.remove(e.j);
					dist[e.j] = dist[i] + e.d;
					q.add(e.j);
				}
				else if(dist[i] == dist[e.j] + e.d) e.c = 1;
			}
		}

		HashMap<Integer,ArrayList<Integer>> layers = new HashMap<>();
		for(int i = 0; i < n; i++) if(cnt[i] > 0)
		{
			if(!layers.containsKey(dist[i]))
				layers.put(dist[i], new ArrayList<Integer>());
			layers.get(dist[i]).add(i);
		}

		int ans = 0;
		for(ArrayList<Integer> layer : layers.values())
		{
			for(int x : layer)
			{
				addEdge(n - 1, x, 0);
				g[n-1].get(g[n-1].size() - 1).c = cnt[x];
			}
			ans += maxFlow(n - 1, 0);
			for(int x : layer)
			{
				g[x].remove(g[x].size() - 1);
				g[n-1].remove(g[n-1].size() - 1);
			}
			for(int i = 0; i < n; i++) for(Edge e : g[i]) e.f = 0;
		}
		System.out.println(ans);
	}

	ArrayList<Edge>[] g;
	int n;

	class Edge
	{
		int j, c, f, d;
		Edge r;

		Edge(int j, int d)
		{
			this.j = j;
			this.d = d;
		}
	}

	void addEdge(int i, int j, int d)
	{
		Edge e = new Edge(j, d), f = new Edge(i, d);
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
