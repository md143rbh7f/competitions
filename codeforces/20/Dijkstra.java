import java.util.*;
import java.io.*;

public class Dijkstra {
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
			System.in)));

	public static void main(String[] args) {
		new Dijkstra().solve();
	}

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < n; i++)
			g.add(new ArrayList<Integer>());
		ArrayList<ArrayList<Integer>> e = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < n; i++)
			e.add(new ArrayList<Integer>());

		while (m-- > 0) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
			g.get(a).add(b);
			e.get(a).add(c);
			g.get(b).add(a);
			e.get(b).add(c);
		}

		final long[] d = new long[n];
		int[] prev = new int[n];
		long INFINITY = (long)2.0e13;
		for (int i = 1; i < n; i++)
			d[i] = INFINITY;

		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				if (d[a] < d[b]) return -1;
				if (d[a] > d[b]) return 1; 
				return a - b;
			}
		});

		// start dijkstra
		q.add(0);
		while (!q.isEmpty()) {
			int u = q.pollFirst();
			for (int i = 0; i < g.get(u).size(); i++) {
				int v = g.get(u).get(i);
				int duv = e.get(u).get(i);
				if (d[v] > d[u] + duv) {
					q.remove(v);
					d[v] = d[u] + duv;
					q.add(v);
					prev[v] = u;
				}
			}
		}
		// end dijkstra

		if (d[n-1] == INFINITY)
			System.out.println(-1);
		else {
			ArrayList<Integer> shortest = new ArrayList<Integer>();
			int ptr = n - 1;
			while (true) {
				shortest.add(ptr);
				if (ptr == 0)
					break;
				ptr = prev[ptr];
			}
			for (int i = shortest.size() - 1; i > 0; i--)
				System.out.print((shortest.get(i) + 1) + " ");
			System.out.println(shortest.get(0) + 1);

		}
	}
}
