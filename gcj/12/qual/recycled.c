#include "stdio.h"

int T, t, a, b, i, j, cnt, ans, pow, seen[10000005];

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d%d", &a, &b );
		pow = 1, ans = 0;
		while( 10 * pow <= b ) pow *= 10;
		for( i = a; i <= b; i++ ) seen[i] = 0;
		for( i = a; i <= b; i++ ) if( !seen[i] )
		{
			j = i, cnt = 0;
			do
			{
				if( a <= j && j <= b ) cnt++, seen[j] = 1;
				j = 10 * ( j % pow ) + j / pow;
			}
			while( j != i );
			ans += cnt * ( cnt - 1 ) / 2;
		}
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
