#include <stdio.h>

int n, s[100000], ans, i, l, r;

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &s[i] );
		r += s[i];
	}
	for( i = 0; i < n-1; i++ )
	{
		l += s[i], r -= s[i];
		if( l==r ) ans++;
	}
	printf( "%d", ans );
	return 0;
}
