public class MinskyMysteryDiv2
{
	public long computeAnswer( long n )
	{
		if( n < 2 ) return -1;
		for( long p = 2; p * p <= n; p++ ) if( n % p == 0 ) return n / p + p;
		return n + 1;
	}
}
