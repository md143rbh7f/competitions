#include "stdio.h"

#define MOD 1000000007
#define N 15
#define M 305
#define D 105
#define Q(x) ((x)%MOD)

int bin[M][D], c[M][M], x[N], d[N], i, j, k, m, n, t;
long long ways[M];

int main()
{
	for( i = 0; i < M; i++ )
	{
		c[i][0] = 1;
		for( j = 1; j <= i; j++ ) c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % MOD;
	}

	scanf( "%d", &t );
	while(t--)
	{
		scanf( "%d%d", &n, &m );
		for( i = 0; i < n; i++ ) scanf( "%d", &x[i] );
		for( i = 0; i < n; i++ ) scanf( "%d", &d[i] );

		ways[0] = 1;
		for( i = 1; i < M; i++ ) ways[i] = 0;
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < M; j++ ) for( k = 0; k < D; k++ ) bin[j][k] = 0;
			bin[0][x[i]] = 1;
			for( j = 0; j < m; j++ ) for( k = 1; k <= d[i]; k++ )
				bin[j+1][k] = Q( bin[j][k-1] + bin[j][k+1] );
			for( j = 0; j <= m; j++ ) for( k = 1; k <= d[i]; k++ )
				bin[j][k] = Q( bin[j][k] + bin[j][k-1] );
			for( j = m; j; j-- ) for( k = 0; k < j; k++ )
				ways[j] = Q( ways[j] + Q( c[j][k] * Q( bin[j-k][d[i]] * ways[k] ) ) );
		}

		printf( "%d\n", (int) ways[m] );
	}

	return 0;
}
