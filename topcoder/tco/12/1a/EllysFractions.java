public class EllysFractions
{
	public long getCount( int n )
	{
		boolean[] p = new boolean[n+1];
		for( int i = 2; i <= n; i++ ) p[i] = true;
		long ans = 0;
		int np = 0;
		for( int i = 2; i <= n; i++ )
		{
			if( p[i] )
			{
				for( int j = 2 * i; j <= n; j += i ) p[j] = false;
				np++;
			}
			ans += 1l << ( np - 1 );
		}
		return ans;
	}
}
