#include <stdio.h>

int n, L;
char buf[101];

int main()
{
	scanf( "%d", &n );
	while(n--)
	{
		scanf( "%s", buf );
		for( L = 0; buf[L]; L++ );
		if( L > 10 ) printf( "%c%d%c\n", buf[0], L-2, buf[L-1] );
		else printf( "%s\n", buf );
	}
	return 0;
}
