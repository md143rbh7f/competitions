#include <stdio.h>

int n[4], a, b, i, ans;

int main()
{
	scanf( "%d%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &a, &b );
	for( i = a; i <= b; i++ ) if( i == ( ( ( ( i % n[0] ) % n[1] ) % n[2] ) % n[3] ) ) ans++;
	printf( "%d\n", ans );
	return 0;
}
