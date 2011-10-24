import java.util.*;

public class PahomOnWater
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int K = in.nextInt();
		while( K-- > 0 )
		{
			int N = in.nextInt(), s = -1, t = -1, x[] = new int[N], y[] = new int[N], r[] = new int[N];
			double f[] = new double[N];
			for( int i = 0; i < N; i++ )
			{
				f[i] = in.nextDouble();
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				r[i] = in.nextInt();
				if( f[i] == 400 ) s = i;
				if( f[i] == 789 ) t = i;
			}
			if( N == 2 )
			{
				System.out.printf( "Game is %s\n", Math.hypot( x[s]-x[t], y[s]-y[t] ) <= r[s]+r[t] ? "VALID" : "NOT VALID" );
				continue;
			}
			int cap[][] = new int[2*N][2*N];
			for( int i = 0; i < N; i++ ) cap[2*i][2*i+1] = 1;
			for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ )
			if( f[i] < f[j] && Math.hypot( x[i]-x[j], y[i]-y[j] ) <= r[i]+r[j] )
				cap[2*i+1][2*j] = 1;
			System.out.printf( "Game is %s\n", max_flow( cap, 2*s+1, 2*t ) >= 2 ? "VALID" : "NOT VALID" );
		}
	}

	static int max_flow( int[][] cap, int s, int t )
	{
		int n = cap.length, flow[][] = new int[n][n];
		int[] prev = new int[n];
		do Arrays.fill( prev, -1 );
		while( max_flow_bfs( cap, flow, prev, s, t, 9001 ) > 0 );
		int max = 0;
		for( int i = 0; i < n; i++ ) max += flow[i][t];
		return max;
	}


	static int max_flow_bfs( int[][] cap, int[][] flow, int[] prev, int s, int t, int minflow )
	{
		LinkedList<Integer> q = new LinkedList<Integer>();
		prev[s] = -2;
		q.add( s );
		while( !q.isEmpty() )
		{
			int i = q.poll();
			for( int j = 0; j < cap.length; j++ ) if( cap[i][j] > flow[i][j] && prev[j] == -1 )
			{
				prev[j] = i;
				q.add( j );
			}
		}
		if( prev[t] == -1 ) return 0;
		int ans = cap[prev[t]][t] - flow[prev[t]][t];
		for( int v = t; prev[v] >= 0; v = prev[v] ) ans = Math.min( ans, cap[prev[v]][v] - flow[prev[v]][v] );
		for( int v = t; prev[v] >= 0; v = prev[v] )
		{
			flow[prev[v]][v] += ans;
			flow[v][prev[v]] -= ans;
		}
		return ans;
	}
}
