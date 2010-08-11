#include <stdio.h>

long long s;
int n, k, i, j, a, b, c, d[300][300];

int main()
{
	scanf( "%d", &n );
	for( i=0; i<n; i++ ) for( j=0;j<n;j++ ) scanf( "%d", &d[i][j] );
	scanf( "%d", &k );
	while( k-- )
	{
		scanf( "%d%d%d", &a, &b, &c );
		a--, b--;
		if( c<d[a][b] ) d[a][b] = d[b][a] = c;
		for( i=0; i<n; i++ ) for( j=0;j<n;j++ ) if( d[i][a]+d[j][b]+c<d[i][j] ) d[i][j] = d[i][a]+d[j][b]+c;
		for( i=0; i<n; i++ ) for( j=0;j<n;j++ ) if( d[i][b]+d[j][a]+c<d[i][j] ) d[i][j] = d[i][b]+d[j][a]+c;
		s = 0;
		for( i=0; i<n; i++ ) for( j=i+1;j<n;j++ ) s += d[i][j];
		printf( "%lld", s );
		if(k) putchar( ' ' );
	}
	return 0;
}
