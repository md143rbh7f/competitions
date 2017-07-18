/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Lizards
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 0; i < c; i++ ) new Lizards().solve( i + 1 );
	}

	// max flow
	void solve( int caseNum )
	{
		int n = in.nextInt(), d = in.nextInt();
		
		char[] line = in.next().toCharArray();
		m = line.length;
		// number of nodes = 2*platforms + source + sink = 2*m*n + 2
		int nodes = 2*n*m+2, source = nodes-2, sink = nodes-1;
		// index of in node = convert(i,j); out node = convert(i,j)+1
		int[][] cap = new int[nodes][nodes];
		// platforms
		for( int i = 0; i < n; i++ )
		{
			if( i != 0 ) line = in.next().toCharArray();
			for( int j = 0; j < m; j++ )
			{
				int in = convert(i,j), out = in + 1;
				// cap from in to out node = jumps
				cap[in][out] = line[j] - '0';
				// cap from out to neighbors = inf
				for( int k = -d; k <= d; k++ )
				{
					for( int l = -d; l <= d; l++ )
					{
						int tx = i + k, ty = j + l;
						int dist2 = k*k+l*l;
						if( dist2 <= d*d && dist2 != 0 )
						{
							// neighbors
							if( tx >= 0 && tx < n && ty >= 0 && ty < m ) cap[out][convert(tx,ty)] = INF;
							// escape
							else cap[out][sink] = INF;
						}
					}
				}
			}
		}
		// lizards
		int liz = 0;
		for( int i = 0; i < n; i++ )
		{
			line = in.next().toCharArray();
			for( int j = 0; j < m; j++ )
			{
				if( line[j] == 'L' )
				{
					// link to source
					cap[source][convert(i,j)] = 1;
					liz++;
				}
			}
		}

		int left = liz - maxflow( cap, source, sink );
		System.out.println( "Case #" + caseNum + ": " + ( left == 0 ? "no" : left ) + " lizard" + ( left > 1 ? "s were" : " was" ) + " left behind." );

	}

	int m;
	int convert( int x, int y )
	{
		return 2 * ( x * m + y );
	}

	int maxflow( int[][] cap, int s, int t )
	{
		int[][] flow = new int[cap.length][cap.length];
		boolean[] seen;
		do seen = new boolean[cap.length];
		while( search( cap, flow, seen, s, t, INF ) != -1 );
		int max = 0;
		for( int i = 0; i < flow.length; i++ ) max += flow[i][t];
		return max;
	}

	// return value = min available flow across all edges in path, if said path exists (otherwise -1)
	int search( int[][] cap, int[][] flow, boolean[] seen, int s, int t, int minflow )
	{
		if( s == t ) return minflow;
		if( seen[s] ) return -1;
		seen[s] = true;
		for( int i = 0; i < flow.length; i++ )
		{
			int residual = cap[s][i] - flow[s][i];
			if( residual <= 0 ) continue;
			int minflow2 = Math.min( minflow, residual );
			minflow2 = Math.min( minflow2, search( cap, flow, seen, i, t, minflow2 ) );
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
