#include "stdio.h"

#define N 105

int n, m, ans, e[N][N];

int cnt( int u, int p )
{
	int v, ans = 1;
	for( v = 0; v < n; v++ ) if( e[u][v] && v != p ) ans += cnt( v, u );
	return ans;
}

int main()
{
	scanf( "%d%d", &n, &m );

	int a, b;
	while( m-- )
	{
		scanf( "%d%d", &a, &b );
		a--, b--;
		e[a][b] = e[b][a] = 1;
	}

	for( a = 0; a < n; a++ ) for( b = a+1; b < n; b++ ) if( e[a][b] )
	{
		e[a][b] = e[b][a] = 0;
		if( cnt( a, -1 ) % 2 == 0 && cnt( b, -1 ) % 2 == 0 ) ans++;
		e[a][b] = e[b][a] = 1;
	}

	printf( "%d\n", ans );

	return 0;
}
