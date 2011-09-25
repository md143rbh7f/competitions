import java.math.*;
import java.util.*;

public class GreenWarfare
{
	int INF = 123456789;

	public int minimumEnergyCost( int[] xc, int[] yc, int[] xb, int[] yb, int[] xp, int[] yp, int r )
	{
		int nc = xc.length, nb = xb.length, np = xp.length, n = nb+np+2, s = n-2, t = n-1, g[][] = new int[n][n];
		for( int i = 0; i < nb; i++ )
		{
			int min = INF;
			for( int j = 0; j < nc; j++ ) min = Math.min( d2(xb[i],yb[i],xc[j],yc[j]), min );
			g[s][i] = min;
		}
		for( int i = 0; i < np; i++ )
		{
			int min = INF;
			for( int j = 0; j < nc; j++ ) min = Math.min( d2(xp[i],yp[i],xc[j],yc[j]), min );
			g[i+nb][t] = min;
		}
		for( int i = 0; i < nb; i++ ) for( int j = 0; j < np; j++ )
		if( Math.hypot( xb[i] - xp[j], yb[i] - yp[j] ) <= r )
			g[i][j+nb] = INF;
		return max_flow( g, s, t );
	}

	int d2( int x1, int y1, int x2, int y2 ) { return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); }

	int max_flow( int[][] cap, int s, int t )
	{
		int n = cap.length, flow[][] = new int[n][n];
		int[] prev = new int[n];
		do Arrays.fill( prev, -1 );
		while( max_flow_bfs( cap, flow, prev, s, t, INF ) > 0 );
		int max = 0;
		for( int i = 0; i < n; i++ ) max += flow[i][t];
		return max;
	}

	int max_flow_bfs( int[][] cap, int[][] flow, int[] prev, int s, int t, int minflow )
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
