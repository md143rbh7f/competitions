int dp[1001][1000], mod = 1000000007;

struct PuyoPuyo
{
	int theCount( int L, int N )
	{
		dp[0][0] = 1;
		for( int i = 0; i < N; i++ )
		{
			dp[i+1][L-1] = (dp[i+1][L-1]+((long long)4*dp[i][0]))%mod;
			for( int j = 1; j < N; j++ ) dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%mod;
			for( int j = 1; j < N; j++ ) if( j+L-1 < N ) dp[i+1][j+L-1] = (dp[i+1][j+L-1]+((long long)3*dp[i][j]))%mod;
		}
		return dp[N][0];
	}
};
