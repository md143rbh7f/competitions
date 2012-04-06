#include "stdio.h"

int n, m, i, ans;

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) scanf( "%d", &m ), ans += ( i + 1 ) * m;
	printf( "%d\n", ans );
	return 0;
}
