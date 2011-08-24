public class Police
{
	public int minimalCost( int[] c, String[] G )
	{
		int n = c.length, ans = 0;
		boolean g[][] = new boolean[n][n], seen[] = new boolean[n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) g[i][j] = G[i].charAt(j)=='Y';
		for( int k = 0; k < n; k++ ) for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) g[i][j] |= g[i][k] && g[k][j];
		for( int i = 0; i < n; i++ ) if( !seen[i] )
		{
			seen[i] = true;
			int best = c[i];
			for( int j = 0; j < n; j++ ) if( g[i][j] && g[j][i] )
			{
				seen[j] = true;
				if( c[j] < best ) best = c[j];
			}
			ans += best;
		}
		return ans;
	}
}
