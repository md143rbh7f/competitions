int dp[50][1000], mod = 1000000007;


struct TheCowDivTwo
{
	int find( int N, int K )
	{
		dp[0][0] = 1;
		for( int i = 0; i < N; i++ ) for( int j = K-1; j >= 0; j-- ) for( int k = 0; k < N; k++ ) dp[j+1][k] = ( dp[j+1][k] + dp[j][(k-i+N)%N] ) % mod;
		return dp[K][0];
	}
};
