import java.io.*;
import java.math.*;
import java.util.*;

public class dolls2
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 9001;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new dolls2().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;
		int d[][] = new int[n][3];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < 3; j++ ) d[i][j] = in.nextInt();
		int N = 2*n+2, g[][] = new int[N][N];
		for( int i = 0; i < n; i++ ) g[N-2][i] = g[i+n][N-1] = 1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		{
			boolean ok = true;
			for( int k = 0; k < 3; k++ ) if( d[i][k] <= d[j][k] ) ok = false;
			if( ok ) g[i][j+n] = 1;
		}
		System.out.println( n - maxflow( g, N-2, N-1 ) );
		return true;
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
