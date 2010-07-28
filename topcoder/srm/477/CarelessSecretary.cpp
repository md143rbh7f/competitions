typedef long long ll;

int i, j;
ll mod = 1000000007, dp[1001][13];

struct CarelessSecretary
{
	int howMany( int N, int K )
	{
		dp[0][0] = 1;
		for( i = 1; i <= N; i++ )
		{
			for( j = 0; j <= i && j <= K; j++ ) dp[i][j] = (dp[i][j]+((i-j)*dp[i-1][j])%mod)%mod;
			for( j = 1; j <= i && j <= K; j++ ) dp[i][j] = (dp[i][j]+((i-j)*dp[i-2][j-1])%mod)%mod;
			for( j = 2; j <= i && j <= K; j++ ) dp[i][j] = (dp[i][j]+((j-1)*dp[i-1][j-1])%mod)%mod;
			for( j = 2; j <= i && j <= K; j++ ) dp[i][j] = (dp[i][j]+((j-1)*dp[i-2][j-2])%mod)%mod;
		}
		return dp[N][K];
	}
};
