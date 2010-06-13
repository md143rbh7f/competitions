#include <stdio.h>

int n, k, i, j, l, p[1001], P[1001];

int main()
{
	scanf( "%d%d", &n, &k );
	for( i = 2; i <= n; i++ ) p[i] = 1;
	for( i = 2; i <= n; i++ ) if( p[i] )
	{
		P[l++] = i;
		for( j = 2*i; j <= n; j += i ) p[j] = 0;
	}
	for( i = 1; i < l; i++ ) if( P[i-1]+P[i]+1<=n && p[P[i-1]+P[i]+1] ) k--;
	if( k<=0 ) printf( "YES" );
	else printf( "NO" );
	return 0;
}
