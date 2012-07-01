#include "stdio.h"

#define N 262144

int tree[N], flip[N], n, m, op, a, b;

inline int get( int x, int i, int j ) { return flip[x] ? j - i - tree[x] : tree[x]; }

int query( int x, int i, int j )
{
	if( a >= j || i >= b ) return 0;
	if( a <= i && j <= b )
	{
		if( !op ) flip[x] = !flip[x];
		return get( x, i, j );
	}
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	if( flip[x] ) flip[y] = !flip[y], flip[z] = !flip[z], flip[x] = 0;
	int ans = query( y, i, k ) + query( z, k, j );
	tree[x] = get( y, i, k ) + get( z, k, j );
	return ans;
}

int main()
{
	scanf( "%d%d", &n, &m );
	while( m-- )
	{
		scanf( "%d%d%d", &op, &a, &b );
		a--;
		if( op ) printf( "%d\n", query( 1, 0, n ) );
		else query( 1, 0, n );
	}
	return 0;
}
