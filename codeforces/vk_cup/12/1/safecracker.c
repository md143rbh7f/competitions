#include "stdio.h"

#define S 5
#define N 100000

int L, p[N], r[S], a[S][S], ten[S], cnt[N][S];

int g()
{
	int i, j, ans = 1;
	for( i = 1; i < L; i++ )
	{
		r[i] = 0;
		for( j = 0; j < L; j++ ) r[i] = 10 * r[i] + a[i][j];
		ans *= cnt[r[i]][L-i-1];
	}
	return ans;
}

int f( int x, int y )
{
	if( x == L ) return g();
	if( y == L ) return f( x + 1, 0 );
	if( y <= x ) return f( x, y + 1 );
	int ans = 0;
	for( a[x][y] = 0; a[x][y] < 10; a[x][y]++ )
	{
		a[y][x] = a[x][y];
		ans += f( x, y + 1 );
	}
	return ans;
}

int main()
{
	int i, j, t, x;
	for( i = 2; i < N; i++ ) p[i] = 1;
	for( i = 2; i < N; i++ ) if( p[i] ) for( j = 2 * i; j < N; j += i ) p[j] = 0;

	ten[0] = 1;
	for( i = 1; i < S; i++ ) ten[i] = ten[i-1] * 10;

	for( i = 0; i < N; i++ ) if( p[i] ) for( j = 0; j < S; j++ ) cnt[ i - ( ( i / ten[j] ) % 10 ) * ten[j] ][j]++;

	scanf( "%d", &t );
	while(t--)
	{
		scanf( "%d", &x );
		r[0] = x;
		for( L = 0; x; L++ ) x /= 10;
		x = r[0];
		for( i = L-1; i >= 0; i-- )
		{
			a[0][i] = a[i][0] = x % 10;
			x /= 10;
		}
		printf( "%d\n", f( 1, 2 ) );
	}
	return 0;
}
