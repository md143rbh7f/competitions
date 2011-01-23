#include <stdio.h>

#define N 15

int t[N][N], i, j;

int main()
{
	for( i = 0; i < N; i++ ) for( j = 0; j <= i; j++ ) scanf( "%d", &t[i][j] );
	for( i = N-2; i >= 0; i-- ) for( j = i; j >= 0; j-- ) t[i][j] += t[i+1][j] > t[i+1][j+1] ? t[i+1][j] : t[i+1][j+1];
	printf( "%d\n", t[0][0] );
	return 0;
}
