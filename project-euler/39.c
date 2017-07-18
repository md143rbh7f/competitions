#include <stdio.h>

int p, a, b, c, n, m, ans;

int main()
{
	for( p = 1; p <= 1000; p++ )
	{
		n = 0;
		for( a = 1; a < p/2; a++ ) for( b = a; b < p/2; b++ )
		{
			c = p - a - b;
			if( c*c == a*a + b*b ) n++;
		}
		if( n > m )
		{
			m = n;
			ans = p;
		}
	}
	printf( "%d\n", ans );
	return 0;
}
