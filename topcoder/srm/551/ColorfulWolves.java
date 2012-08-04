public class ColorfulWolves
{
	public final static int OVER_NINE_THOUSAND = 9001;

	public int getmin( String[] g )
	{
		int n = g.length, d[][] = new int[n][n];
		for( int i = 0; i < n; i++ )
		{
			int cnt = 0;
			for( int j = 0; j < n; j++ ) d[i][j] = g[i].charAt(j) == 'Y' ? cnt++ : OVER_NINE_THOUSAND;
		}
		for( int k = 0; k < n; k++ ) for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) d[i][j] = Math.min( d[i][j], d[i][k] + d[k][j] );
		return d[0][n-1] < OVER_NINE_THOUSAND ? d[0][n-1] : -1;
	}
}
