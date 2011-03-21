#include <stdio.h>

#define N 10001

int e[N], n, k, i;
double ans, d = 1024, t, over, under, r;

int main()
{
	scanf( "%d%d", &n, &k );
	r = 1.0 - 1.0 * k / 100;
	for( i = 0; i < n; i++ ) scanf( "%d", &e[i] );
	while( d )
	{
		t = ans + d, over = under = 0;
		for( i = 0; i < n; i++ )
		{
			if( e[i] > t ) over += e[i]-t;
			else under += t-e[i];
		}
		if( over*r >= under ) ans = t;
		d /= 2;
	}
	printf( "%.9f\n", ans );
	return 0;
}
