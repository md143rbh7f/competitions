#include "stdio.h"

#define rep(i,n) for(i=0;i<(n);i++)

#define N 13
#define S 9
#define MOD 1007

int n, m, g[N][N], ways[S+1][1<<N], i, j, k;

int main()
{
	scanf( "%d%d", &n, &m );
	while( m-- )
	{
		scanf( "%d%d", &i, &j );
		g[i][j] = 1;
	}

	m = 1<<n;
	rep(i,m)
	{
		ways[0][i] = 1;
		rep(j,n) rep(k,n) if( g[j][k] && !((i>>j)&1) && (i>>k)&1 ) ways[0][i] = 0;
	}

	rep(i,S) rep(j,m) for( k = j; k < m; k = (k+1)|j ) if( ways[0][k] ) ways[i+1][k] = ( ways[i+1][k] + ways[i][j] ) % MOD;

	printf( "%d\n", ways[S][m-1] );

	return 0;
}
