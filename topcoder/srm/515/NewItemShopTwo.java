public class NewItemShopTwo
{
	int id[] = new int[25], c[] = new int[25];
	double p[] = new double[25], dp[][] = new double[25][4];
	
	public double getMaximum( String[] customers )
	{
		for( int i = 0; i < 25; i++ ) id[i] = -1;
		for( int i = 0; i < 2; i++ )
		{
			String entries[] = customers[i].split( " " );
			double P = 100;
			for( String entry : entries )
			{
				String s[] = entry.split( "," );
				int t = Integer.parseInt( s[0] );
				c[t] = Integer.parseInt( s[1] );
				int pct = Integer.parseInt( s[2] );
				p[t] = pct / P;
				P -= pct;
				id[t] = i;
			}
		}
		for( int t = 23; t >= 0; t-- ) for( int m = 0; m < 4; m++ )
			dp[t][m] = ( id[t] == -1 || (m>>id[t])%2 == 1 ) ? dp[t+1][m] : ( 1 - p[t] ) * dp[t+1][m] + p[t] * Math.max( c[t], dp[t+1][m|(1<<id[t])] );
		return dp[0][0];
	}
}
