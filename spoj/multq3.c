#include "stdio.h"

#define N 262144
#define update_tree tree[x][0] = get( y, 0 ) + get( z, 0 ); tree[x][1] = get( y, 1 ) + get( z, 1 ); tree[x][2] = get( y, 2 ) + get( z, 2 )

int tree[N][3], add[N], n, m, op, a, b;

void init( int x, int i, int j )
{
	if( i >= n ) return;
	if( i + 1 == j )
	{
		tree[x][0]++;
		return;
	}
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	init( y, i, k ), init( z, k, j );
	tree[x][0] = tree[y][0] + tree[z][0];
}

// The solution won't pass in time without these optimisations:
inline int m3( int x ) { return x - x / 3 * 3; }
inline int get( int x, int k ) { return tree[x][m3(k+add[x])]; }
inline int next_int()
{
	int n = 0;
	char c;
	do c = getchar_unlocked();
	while( c < '0' || '9' < c );
	while( '0' <= c && c <= '9' )
	{
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

void inc( int x, int i, int j )
{
	if( a >= j || i >= b ) return;
	if( a <= i && j <= b )
	{
		add[x] = m3( add[x] + 2 );
		return;
	}
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	add[y] = m3( add[y] + add[x] ), add[z] = m3( add[z] + add[x] ), add[x] = 0;
	inc( y, i, k ), inc( z, k, j );
	update_tree;
}

int query( int x, int i, int j )
{
	if( a >= j || i >= b ) return 0;
	if( a <= i && j <= b ) return get( x, 0 );
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	add[y] = m3( add[y] + add[x] ), add[z] = m3( add[z] + add[x] ), add[x] = 0;
	int ans = query( y, i, k ) + query( z, k, j );
	update_tree;
	return ans;
}

int main()
{
	n = next_int(), m = next_int();
	init( 1, 0, n );
	while( m-- )
	{
		op = next_int(), a = next_int(), b = next_int() + 1;
		if( op ) printf( "%d\n", query( 1, 0, n ) );
		else inc( 1, 0, n );
	}
	return 0;
}
