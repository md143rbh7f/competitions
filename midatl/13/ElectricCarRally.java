import java.io.*;
import java.math.*;
import java.util.*;

public class ElectricCarRally
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int INF = 1234567890, C = 240, T = 1440;

	public static void main(String[] args)
	{
		while(new ElectricCarRally().run());
	}

	int[][] d;
	TreeSet<State> q;

	void update(State s, int ti, int tc, int dst)
	{
		if(d[ti][tc] > d[s.i][s.c] + dst)
		{
			State t = new State(ti, tc);
			q.remove(t);
			d[ti][tc] = d[s.i][s.c] + dst;
			q.add(t);
		}
	}

	boolean run()
	{
		int n = in.nextInt(), m = in.nextInt();
		if(n == 0) return false;
		ArrayList<Route>[] g = new ArrayList[n];
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Route>();
		while(m --> 0)
		{
			int a = in.nextInt(), b = in.nextInt();
			ArrayList<Edge> es = new ArrayList<Edge>();
			Edge e;
			do es.add(e = new Edge(in.nextInt(), in.nextInt(), in.nextInt()));
			while(e.stop != T - 1);
			g[a].add(new Route(b, es));
			g[b].add(new Route(a, es));
		}

		d = new int[n][C + 1];
		for(int i = 0; i < n; i++) Arrays.fill(d[i], INF);
		q = new TreeSet<State>();
		d[0][C] = T / 2;
		q.add(new State(0, C));
		while(true)
		{
			State s = q.pollFirst();
			if(s.i == n - 1)
			{
				System.out.println(d[s.i][s.c] - T / 2);
				break;
			}
			if(s.c < C) update(s, s.i, s.c + 1, 2);
			for(Route r : g[s.i]) for(Edge e : r.e) if(e.time <= C)
			{
				int wait = Math.max(0, 2 * (e.time - s.c)), dm = (d[s.i][s.c] + wait) % T;
				if(dm < e.start) wait += e.start - dm;
				else if(dm > e.stop) wait += e.start + T - dm;
				update(s, r.t, Math.min(C, s.c + wait / 2) - e.time, wait + e.time);
			}
		}
		return true;
	}

	class State implements Comparable<State>
	{
		int i, c;

		public State(int i, int c)
		{
			this.i = i;
			this.c = c;
		}
		
		public int compareTo(State o)
		{
			if(d[i][c] != d[o.i][o.c]) return d[i][c] - d[o.i][o.c];
			if(i != o.i) return i - o.i;
			return c - o.c;
		}
	}

	class Route
	{
		int t;
		ArrayList<Edge> e;

		Route(int t, ArrayList<Edge> e)
		{
			this.t = t;
			this.e = e;
		}
	}

	class Edge
	{
		int start, stop, time;

		Edge(int start, int stop, int time)
		{
			this.start = start;
			this.stop = stop;
			this.time = time;
		}
	}
}
