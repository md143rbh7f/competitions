#include "stdio.h"

#define N 205
#define MOD 1000000007ll

char buf[N];
int ok[2*N][2*N];
long long ways[N][2*N][2*N];

void run()
{
	int n, m, s, i, j, u, v, nn, u0, v0, u1, v1;
	scanf( "%d%d%d", &n, &m, &s );

	nn = 2 * n;
	for( u = 1; u < nn; u++ ) for( v = 1; v < nn; v++ ) ok[u][v] = 0;

	for( i = 0; i < n; i++ )
	{
		scanf( "%s", buf );
		for( j = 0; j < n; j++ )
		{
			u = i + j + 1, v = i - j + n;
			ok[u][v] = buf[j] != 'P';
			if( buf[j] == 'L' ) u0 = u, v0 = v;
		}
	}

	for( u = 1; u < nn; u++ ) for( v = 1; v < nn; v++ ) ways[0][u][v] = u >= u0 && v >= v0;

	for( i = 1; i <= m; i++ ) for( u = 1; u < nn; u++ ) for( v = 1; v < nn; v++ )
	{
		ways[i][u][v] = ways[i][u-1][v] + ways[i][u][v-1] - ways[i][u-1][v-1];
		if( ok[u][v] )
		{
			u0 = u > s ? u - s - 1 : 0, u1 = u + s < nn ? u + s : nn - 1;
			v0 = v > s ? v - s - 1 : 0, v1 = v + s < nn ? v + s : nn - 1;
			ways[i][u][v] += ways[i-1][u1][v1] - ways[i-1][u0][v1] - ways[i-1][u1][v0] + ways[i-1][u0][v0];
		}
		ways[i][u][v] = ( ways[i][u][v] + 3 * MOD ) % MOD;
	}

	printf( "%lld\n", ways[m][nn-1][nn-1] );
}

int main()
{
	int t;
	scanf( "%d", &t );
	while( t-- ) run();
	return;
}
