public class MagicStonesStore
{
	public String ableToDivide( int n )
	{
		n *= 2;
		boolean[] p = new boolean[n];
		for( int i = 2; i < n; i++ ) p[i] = true;
		for( int i = 2; i < n; i++ ) if( p[i] ) for( int j = 2 * i; j < n; j += i ) p[j] = false;
		for( int i = 2; i < n; i++ ) if( p[i] && p[n-i] ) return "YES";
		return "NO";
	}
}
