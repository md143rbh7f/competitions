#include "stdio.h"

#define T (1<<17)

int t, d, m, tree[2*T], lazy[2*T];

inline int max( int a, int b ) { return a > b ? a : b; }

int init( int x, int i, int j )
{
	if( i + 1 == j ) return tree[x] = -i;
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	return tree[x] = max( init( y, i, k ), init( z, k, j ) );
}

int query( int x, int i, int j )
{
	if( j <= d ) return tree[x] + lazy[x];
	if( i >= d ) return tree[x] + ( lazy[x] += m );
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	if( lazy[x] ) lazy[y] += lazy[x], lazy[z] += lazy[x], lazy[x] = 0;
	return tree[x] = max( query( y, i, k ), query( z, k, j ) );
}

int main()
{
	init( 1, 0, T );
	scanf( "%d", &t );
	while(t--)
	{
		scanf( "%d%d", &d, &m );
		printf( "%d\n", query( 1, 0, T ) );
	}
	return 0;
}
