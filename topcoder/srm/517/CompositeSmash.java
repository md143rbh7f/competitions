public class CompositeSmash
{
	int dp[] = new int[100001];

	boolean must( int n, int m )
	{
		if( n % m != 0 ) return false;
		if( n == m ) return true;
		if( dp[n] > 0 ) return dp[n] == 1;
		dp[n] = 1;
		for( int i = 2; i * i <= n; i++ ) if( n % i == 0 ) if( !( must( i, m ) || must( n/i, m ) ) ) dp[n] = -1;
		return dp[n] == 1;
	}
	
	public String thePossible( int n, int m )
	{
		return must( n, m ) ? "Yes" : "No";
	}
}
