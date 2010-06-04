#include <stdio.h>

#define MAX 1000

int T, t, n, e[MAX][2], i, j, ans;

int comp( int a[], int b[] ) { return a[0]-b[0]; }

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d", &n );
		for( i = 0; i < n; i++ )
		{
			scanf( "%d", &e[i][0] );
			scanf( "%d", &e[i][1] );
		}
		qsort( e, n, sizeof(e[0]), comp );
		ans = 0;
		for( i = 0; i < n; i++ ) for( j = 0; j < i; j++ ) if( e[i][1] < e[j][1] ) ans++;
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
