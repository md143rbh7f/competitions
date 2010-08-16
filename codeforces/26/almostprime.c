#include <stdio.h>

#define MAX 3000

int p[MAX+1], f[MAX+1], n, c, i, j;

int main()
{
	scanf( "%d", &n );
	for( i=2; i<=n; i++ ) p[i] = 1;
	for( i=2; i<=n; i++ ) if( p[i] ) for( j=2*i; j<=MAX; j+=i ) p[j] = 0, f[j]++;
	for( i=2; i<=n; i++ ) if( f[i]==2 ) c++;
	printf( "%d", c );
	return 0;
}
