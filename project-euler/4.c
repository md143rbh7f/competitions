#include <stdio.h>

int a, b, n, ans, d[6], i, l, ok;

int main()
{
	for( a = 1; a < 1000; a++ ) for( b = a; b < 1000; b++ )
	{
		n = a*b, l = 0, ok = 1;
		while(n) d[l++] = n%10, n /= 10;
		for( i = 0; i < l; i++ ) if( d[i]!=d[l-i-1] ) ok = 0;
		if( ok && a*b>ans ) ans = a*b;
	}
	printf( "%d\n", ans );
	return 0;
}
