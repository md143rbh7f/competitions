#include <stdio.h>

int n, k, t, i, a, b;

int main()
{
	scanf( "%d%d%d", &n, &k, &t );
	b = n*k*t;
	for( i = 0; i < n; i++ )
	{
		if(i) printf( " " );
		if( a + 100*k < b )
		{
			printf( "%d", k );
			a += 100*k;
		}
		else if( a < b )
		{
			printf( "%d", (b-a)/100 );
			a = b;
		}
		else printf( "0" );
	}
	printf( "\n" );
	return 0;
}
