public class CountingSeries
{
	public long countThem( long a, long b, long c, long d, long MAX )
	{
		long ans = a <= MAX ? ( MAX - a ) / b + 1 : 0;
		if( d == 1 ) { if( c <= MAX && ( c < a || c%b != a%b ) ) ans++; }
		else for( long n = c; n <= MAX; n *= d ) if( n <= MAX && ( n < a || n%b != a%b ) ) ans++;
		return ans;
	}
}
