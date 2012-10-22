#define MOD 555555555
#define N 600

int odd[N][N], choose[N][N];

struct MuddyRoad2
{
	int theCount( int n, int m )
	{
		for( int i = 0; i <= n; i++ )
		{
			choose[i][0] = 1;
			for( int j = 1; j <= i; j++ )
				choose[i][j] = ( choose[i-1][j] + choose[i-1][j-1] ) % MOD;
		}

		for( int i = 1; i <= n; i++ ) if( i % 3 ) odd[i][0] = 1;
		for( int i = 3; i <= n; i++ ) for( int j = 1; j <= m; j++ )
			odd[i][j] = ( odd[i-3][j] + odd[i-3][j-1] + odd[i-2][j-1] ) % MOD;

		return ( choose[n-2][m] - odd[n][m] + MOD ) % MOD;
	}
};
