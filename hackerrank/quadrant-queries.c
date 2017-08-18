#include "stdio.h"

#define N 262144

char code[2];
int tree[N][4], flip[N][2], n, a, b, d, ans[4];

void init( int x, int i, int j )
{
	if( i >= n ) return;
	if( i + 1 == j )
	{
		int tx, ty;
		scanf( "%d%d", &tx, &ty );
		if( tx > 0 && ty > 0 ) tree[x][0]++;
		else if( ty > 0 ) tree[x][1]++;
		else if( tx > 0 ) tree[x][3]++;
		else tree[x][2]++;
		return;
	}
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	init( y, i, k ), init( z, k, j );
	for( k = 0; k < 4; k++ ) tree[x][k] = tree[y][k] + tree[z][k];
}

inline int get( int x, int q )
{
	if( flip[x][0] ) q = 3-q;
	if( flip[x][1] ) q = q^1;
	return tree[x][q];
}

void query( int x, int i, int j )
{
	if( a >= j || i >= b ) return;
	int l;
	if( a <= i && j <= b )
	{
		if( d > -1 ) flip[x][d] = !flip[x][d];
		else for( l = 0; l < 4; l++ ) ans[l] += get( x, l );
		return;
	}
	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	for( l = 0; l < 2; l++ ) if( flip[x][l] ) flip[y][l] = !flip[y][l], flip[z][l] = !flip[z][l], flip[x][l] = 0;
	query( y, i, k ), query( z, k, j );
	for( l = 0; l < 4; l++ ) tree[x][l] = get( y, l ) + get( z, l );
}

int main()
{
	scanf( "%d", &n );
	init( 1, 0, n );
	int i, m;
	scanf( "%d", &m );
	while( m-- )
	{
		scanf( "%s%d%d", code, &a, &b );
		a--;
		switch( code[0] )
		{
			case 'C':
				for( i = 0; i < 4; i++ ) ans[i] = 0;
				d = -1;
				query( 1, 0, n );
				printf( "%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3] );
				break;
			case 'X':
				d = 0;
				query( 1, 0, n );
				break;
			case 'Y':
				d = 1;
				query( 1, 0, n );
				break;
		}
	}
	return 0;
}
