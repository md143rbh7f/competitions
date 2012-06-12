#include <cstdio>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

#define N 1505

int n, m, dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 }, prev_x[N][N], prev_y[N][N];
bool seen[N][N];
char maze[N][N];

bool dfs( int x, int y )
{
	int mx = ( ( x % n ) + n ) % n, my = ( ( y % m ) + m ) % m;
	if( maze[mx][my] == '#' ) return false;

	int & px = prev_x[mx][my], & py = prev_y[mx][my];
	if( seen[mx][my] ) return px != x || py != y;

	px = x, py = y, seen[mx][my] = true;
	rep(d,4) if( dfs( x + dx[d], y + dy[d] ) ) return true;
	return false;
}

int main()
{
	scanf( "%d%d", &n, &m );
	rep(i,n) scanf( "%s", maze[i] );
	rep(i,n) rep(j,m) if( maze[i][j] == 'S' ) printf( dfs( i, j ) ? "Yes\n" : "No\n" );
	return 0;
}
