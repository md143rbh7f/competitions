#include "stdio.h"

#define rep(i,n) for(i=0;i<(n);i++)

#define MOD 1000000007
#define N 25
#define M 8
#define B 8

int n, m, tm, tm2, grid[N], ways[N][1<<(2*M)], width[B] = { 1, 1, 1, 1, 2, 2, 3, 3 }, b[M][B];
char buf[M+1];

int make_brick( int a, int b, int c, int d )
{
	return ( tm2 * a + tm * b + c ) << d;
}

void rec( int x, int y, int s0, int s1 )
{
	if( y == m )
	{
		ways[x+1][s1] = ( ways[x+1][s1] + ways[x][s0] ) % MOD;
		return;
	}

	if( ( ( s0 / tm ) >> y ) & 1 )
	{
		rec( x, y + 1, s0, s1 );
		return;
	}

	int i;
	rep(i,B) if( b[y][i] && ( ( b[y][i] / tm ) & s0 ) == 0 && ( b[y][i] & s1 ) == 0 )
		rec( x, y + width[i], s0, s1 ^ ( b[y][i] % tm2 ) );
}

void run()
{
	int i, j;
	scanf( "%d%d", &n, &m );
	tm = 1<<m, tm2 = 1<<(2*m);

	rep(i,m)
	{
		b[i][0] = i + 2 <= m ? make_brick( 1, 1, 3, i ) : 0;
		b[i][1] = i - 1 >= 0 ? make_brick( 2, 2, 3, i - 1 ) : 0;
		b[i][2] = i + 3 <= m ? make_brick( 1, 7, 0, i ) : 0;
		b[i][3] = i - 2 >= 0 ? make_brick( 4, 7, 0, i - 2 ) : 0;
		b[i][4] = i + 2 <= m ? make_brick( 3, 1, 1, i ) : 0;
		b[i][5] = i + 2 <= m ? make_brick( 3, 2, 2, i ) : 0;
		b[i][6] = i + 3 <= m ? make_brick( 7, 1, 0, i ) : 0;
		b[i][7] = i + 3 <= m ? make_brick( 7, 4, 0, i ) : 0;
	}

	rep(i,n)
	{
		grid[i] = 0;
		scanf( "%s", buf );
		rep(j,m) if( buf[j] == '#' ) grid[i] ^= 1<<j;
	}
	grid[n] = grid[n+1] = tm-1;

	rep(i,n+1) rep(j,tm2) ways[i][j] = 0;
	ways[0][ tm * grid[0] + grid[1] ] = 1;
	rep(i,n) rep(j,tm2) if( ways[i][j] ) rec( i, 0, j, ( j % tm ) * tm + grid[i+2] );

	printf( "%d\n", ways[n][tm2-1] );
}

int main()
{
	int t;
	scanf( "%d", &t );
	while( t-- ) run();
	return 0;
}
