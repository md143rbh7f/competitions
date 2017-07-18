#include <cstdio>

using namespace std;

#define L 120

int n, q, w[L], m[L];
long long dp[L];

int main()
{
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d%d", &n, &q );
		if( !n && !q ) break;
		for( int i = 0; i < n; i++ )
			scanf( "%d%d", &w[i], &m[i] );

		dp[0] = 1;
		for( int i = 1; i < L; i++ )
			dp[i] = 0;
		for( int i = 0; i < n; i++ )
		for( int k = 0; k < m[i]; k++ )
		for( int j = L-1; j >= w[i]; j-- )
			dp[j] += dp[j-w[i]];

		printf( "Case %d:", case_num );
		for( int i = 0; i < n; i++ )
		{
			for( int j = w[i]; j < L; j++ )
				dp[j] -= dp[j-w[i]];

			long long tot = 0;
			for( int l = q - 1; l >= 0 && l + w[i] >= q; l-- )
				tot += dp[l];
			printf( " %lld", tot );

			for( int j = L-1; j >= w[i]; j-- )
				dp[j] += dp[j-w[i]];
		}
		printf( "\n" );
	}
	return 0;
}
