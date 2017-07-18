#include <stdio.h>

int i, j, k, l, m, n, ans;

int main()
{
	for( i = j = m = n = ans = 1; n <= 1000000; i++, m = i==10*m ? i : m ) for( k = i, l = m; l; k %= l, l /= 10, n++ ) if( n == j ) ans *= k/l, j *= 10;
	printf( "%d\n", ans );
	return 0;
}
