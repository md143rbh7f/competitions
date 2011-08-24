public class NewItemShop
{
	int id[] = new int[25], c[] = new int[25];
	double p[] = new double[25], dp[][][] = new double[25][25][1<<12];

	public double getMaximum( int swords, String[] customers )
	{
		for( int i = 0; i < 24; i++ ) id[i] = -1;
		int n = customers.length, m = 0;
		for( String customer : customers )
		{
			String entries[] = customer.split(" ");
			int cur_id = entries.length > 1 ? m++ : -1;
			double prior = 100;
			for( String entry : entries )
			{
				String s[] = entry.split(",");
				int t = Integer.parseInt(s[0]);
				c[t] = Integer.parseInt(s[1]);
				int pct = Integer.parseInt(s[2]);
				p[t] = pct / prior;
				prior -= pct;
				id[t] = cur_id;
			}
		}
		for( int t = 23; t >= 0; t-- ) for( int s = 1; s <= swords; s++ ) for( int mask = 0; mask < 1<<m; mask++ )
		{
			if( id[t] < 0 )
				dp[t][s][mask] = ( 1 - p[t] ) * dp[t+1][s][mask] + p[t] * Math.max( dp[t+1][s-1][mask] + c[t], dp[t+1][s][mask] );
			else if( ((mask>>id[t])&1) == 1 )
				dp[t][s][mask] = dp[t+1][s][mask];
			else
				dp[t][s][mask] = ( 1 - p[t] ) * dp[t+1][s][mask] + p[t] * Math.max( dp[t+1][s-1][mask|(1<<id[t])] + c[t], dp[t+1][s][mask|(1<<id[t])] );	
		}
		return dp[0][swords][0];
	}
};
