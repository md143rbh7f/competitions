#include "stdio.h"

int ans, n, p, q, s, t, T;

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d%d%d", &n, &s, &p );
		ans = 0;
		while( n-- )
		{
			scanf( "%d", &q );
			if( q > 3 * p - 3 ) ans++;
			else if( q > 3 * p - 5 && q && s ) ans++, s--;
		}
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
