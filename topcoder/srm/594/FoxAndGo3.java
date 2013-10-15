import java.math.*;
import java.util.*;

public class FoxAndGo3
{
	int x, y, n, m, INF = 12345;
	int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	ArrayList<Integer>[] g;
	int[][] cap;
	int[][] flow;
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
		for(int i = 0; i < n; i++) g[i] = new ArrayList<Integer>();
		cap = new int[n][n];
		flow = new int[n][n];
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
		g[i].add(j);
		g[j].add(i);
		cap[i][j] = c;
	}

	int maxFlow(int s, int t)
	{
		do Arrays.fill(seen, false);
		while(maxFlowDFS(s, t, INF) > 0);
		int max = 0;
		for(int i = 0; i < n; i++) max += flow[i][t];
		return max;
	}

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
}
