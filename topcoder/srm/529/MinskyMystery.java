public class MinskyMystery
{
	final static long MOD = 1000000009;
	public long M( long n ) { return n % MOD; }

	public int computeAnswer( long n )
	{
		if( n < 2 ) return -1;
		long p = 2;
		while( p * p <= n && n % p != 0 ) p++;
		if( n % p != 0 ) p = n;
		long ans = M( M( 4 * M( p - 2 ) + 3 ) * M( n ) + 2 * M( p - 1 ) );
		for( long q = 2; q <= p; q++ )
		{
			long r = n / ( n / q );
			if( r > p ) r = p;
			ans = M( ans + M( r - q + 1 ) * M( n / q ) );
			q = r;
		}
		return (int) ans;
	}
}
