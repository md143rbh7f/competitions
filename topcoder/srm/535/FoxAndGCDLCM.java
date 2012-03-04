public class FoxAndGCDLCM
{
	public long get( long gcd, long lcm )
	{
		if( lcm % gcd != 0 ) return -1;
		long lg = lcm / gcd, c = 0, d = 0;
		for( long i = 1; i * i <= lg; i++ ) if( lg % i == 0 && gcd( i, lg/i ) == 1 )
		{
			c = i;
			d = lg / i;
		}
		return ( c + d ) * gcd;
	}
	
	long gcd( long a, long b )
	{
		while( b != 0 )
		{
			long t = a%b;
			a = b;
			b = t;
		}
		return a;
	}
}
