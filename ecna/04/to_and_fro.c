#include <stdio.h>

char buf[201], out[201];
int l, m, n, i, j;

int main()
{
	while(1)
	{
		scanf( "%d", &n );
		if(!n) break;
		scanf( "%s", buf );
		for( l = 0; buf[l]; l++ );
		m = l/n;
		for( i = 0; i < n; i++ ) for( j = 0; j < m; j += 2 ) out[ i*m + j ] = buf[ i + j*n ];
		for( i = 0; i < n; i++ ) for( j = 1; j < m; j += 2 ) out[ i*m + j ] = buf[ n - i - 1 + j*n ];
		out[l] = 0;
		printf( "%s\n", out );
	}
	return 0;
}
