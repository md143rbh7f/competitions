#include <stdio.h>

int n, m, i, j, bad;
char f[100][100];

int main()
{
	scanf( "%d%d", &n, &m );
	for( i = 0; i < n; i++ ) scanf( "%s", f[i] );
	for( i = 0; i < n; i++ ) for( j = 1; j < m; j++ ) if( f[i][j]!=f[i][j-1] ) bad = 1;
	for( i = 1; i < n; i++ ) if( f[i][0]==f[i-1][0] ) bad = 1;
	if( bad ) printf( "NO\n" );
	else printf( "YES\n" );
	return 0;
}
