#include "stdio.h"

#define N 1000000

int p[N], emirp[11184], i, j, a, b;

int main()
{
	for( i = 2; i < N; i++ ) p[i] = 1;
	for( i = 2; i * i < N; i++ ) if( p[i] ) for( j = 2 * i; j < N; j += i ) p[j] = 0;
	for( j = 0, i = 2; i < N; i++ ) if( p[i] )
	{
		a = i, b = 0;
		while( a )
		{
			b = 10 * b + ( a % 10 );
			a /= 10;
		}
		if( b != i && p[b] ) emirp[j++] = i;
	}
	scanf( "%d", &i );
	printf( "%d\n", emirp[i-1] );
	return 0;
}
