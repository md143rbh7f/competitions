import java.io.*;
import java.math.*;
import java.util.*;

public class Taxi
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Taxi().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt();
		int[] t0 = new int[n], t1 = new int[n], x0 = new int[n], y0 = new int[n], x1 = new int[n], y1 = new int[n];
		for( int i = 0; i < n; i++ )
		{
			String[] t = in.next().split(":");
			t0[i] = 60*Integer.parseInt(t[0])+Integer.parseInt(t[1]);
			x0[i] = in.nextInt(); y0[i] = in.nextInt(); x1[i] = in.nextInt(); y1[i] = in.nextInt();
			t1[i] = t0[i] + Math.abs(x0[i]-x1[i]) + Math.abs(y0[i]-y1[i]);
		}
		int N = 2*n+2, cap[][] = new int[N][N];
		for( int i = 0; i < n; i++ )
		{
			cap[N-2][i] = 1;
			cap[i+n][N-1] = 1;
			for( int j = i+1; j < n; j++ )
			if( t1[i] + Math.abs(x0[j]-x1[i]) + Math.abs(y0[j]-y1[i]) < t0[j] )
				cap[i][j+n] = 1;
		}
		System.out.println( n - maxflow( cap, N-2, N-1 ) );
	}

	int maxflow( int[][] cap, int s, int t )
	{
		int[][] flow = new int[cap.length][cap.length];
		boolean[] seen;
		do seen = new boolean[cap.length];
		while( maxflow_search( cap, flow, seen, s, t, INF ) != -1 );
		int max = 0;
		for( int i = 0; i < flow.length; i++ ) max += flow[i][t];
		return max;
	}

	int maxflow_search( int[][] cap, int[][] flow, boolean[] seen, int s, int t, int minflow )
	{
		if( s == t ) return minflow;
		if( seen[s] ) return -1;
		seen[s] = true;
		for( int i = 0; i < flow.length; i++ )
		{
			int residual = cap[s][i] - flow[s][i];
			if( residual <= 0 ) continue;
			int minflow2 = Math.min( minflow, residual );
			minflow2 = Math.min( minflow2, maxflow_search( cap, flow, seen, i, t, minflow2 ) );
			if( minflow2 != -1 )
			{
				flow[s][i] += minflow2;
				flow[i][s] -= minflow2;
				return minflow2;
			}
		}
		return -1;
	}
}
