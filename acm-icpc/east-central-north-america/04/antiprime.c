#include <stdio.h>

#define MAX 1010
#define MAXP 10000

int n, m, d, p[MAXP], a[MAX], seen[MAX], i, j;

int ok( int x )
{
	if( x > m-n ) return 1;
	for( a[x] = n; a[x] <= m; a[x]++ ) if( !seen[a[x]] )
	{
		int bad = 0;
		j = a[x];
		for( i = 1; i < d && i <= x; i++ )
		{
			j += a[x-i];
			if(p[j]) bad = 1;
		}
		if(bad) continue;
		seen[a[x]] = 1;
		if(ok(x+1))
		{
			seen[a[x]] = 0;
			return 1;
		}
		seen[a[x]] = 0;
	}
	return 0;
}

int main()
{
	for( i = 2; i < MAXP; i++ ) p[i] = 1;
	for( i = 2; i < MAXP; i++ ) if(p[i]) for( j = 2*i; j < MAXP; j += i ) p[j] = 0;
	while(1)
	{
		scanf( "%d%d%d", &n, &m, &d );
		if( !n && !m && !d ) break;
		if(ok(0))
		{
			printf( "%d", a[0] );
			for( i = 1; i <= m-n; i++ ) printf( ",%d", a[i] );
			printf( "\n" );
		}
		else printf( "No anti-prime sequence exists.\n" );
	}
	return 0;
}
