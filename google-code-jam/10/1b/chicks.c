#include <stdio.h>

int C, c, n, k, b, t, x[50], v[50], ok, notok, i, j, ans;

int main()
{
	scanf( "%d", &C );
	for( c = 1; c <= C; c++ )
	{
		scanf( "%d %d %d %d", &n, &k, &b, &t );
		for( i = 0; i < n; i++ ) scanf( "%d", &x[i] );
		for( i = 0; i < n; i++ ) scanf( "%d", &v[i] );
		ans = ok = notok = 0;
		for( i = n-1; i >= 0; i-- )
		{
			if( x[i]+v[i]*t >= b )
			{
				ok++;
				ans += notok;
				if( ok==k ) break;
			}
			else notok++;
		}
		printf( "Case #%d: ", c );
		if( ok==k ) printf( "%d\n", ans );
		else printf( "IMPOSSIBLE\n" );
	}
	return 0;
}
