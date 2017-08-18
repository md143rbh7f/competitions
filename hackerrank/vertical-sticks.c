#include "stdio.h"

#define N 55

long long choose[N][N];
int h[N];

void run()
{
	int i, j, k, m, n;

	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) scanf( "%d", &h[i] );

	double ans = 0;
	for( i = 0; i < n; i++ )
	{
		for( m = j = 0; j < n; j++ ) if( h[j] < h[i] ) m++;

		long long cnt = 0;
		for( j = 0; j <= m; j++ ) cnt += ( j + 1 ) * choose[n-1-j][m-j];
		for( j = 0; j <= m; j++ ) cnt += ( j + 1 ) * ( n - 1 - j ) * choose[n-2-j][m-j];

		ans += 1.0 * cnt / choose[n-1][m] / n;
	}

	printf( "%.2f\n", ans );
}

int main()
{
	int i, j, t;

	choose[0][0] = 1;
	for( i = 1; i < N; i++ )
	{
		choose[i][0] = 1;
		for( j = 1; j <= i; j++ ) choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	}

	scanf( "%d", &t );
	while( t-- ) run();

	return 0;
}
