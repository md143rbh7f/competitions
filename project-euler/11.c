#include <stdio.h>

#define MAX 20
#define L 4
#define D 4

int g[MAX+8][MAX+8], i, j, n, ans, d, t, dx[] = { 1, 0, 1, -1 }, dy[] = { 0, 1, 1, 1 };

int main()
{
	for( i = 0; i < MAX; i++ ) for( j = 0; j < MAX; j++ ) scanf( "%d", &g[i+4][j+4] );
	for( i = 0; i < MAX; i++ ) for( j = 0; j < MAX; j++ ) for( d = 0; d < 4; d++ )
	{
		n = 1;
		for( t = 0; t < L; t++ ) n *= g[i+4+dx[d]*t][j+4+dy[d]*t];
		if( n > ans ) ans = n;
	}
	printf( "%d\n", ans );
	return 0;
}
