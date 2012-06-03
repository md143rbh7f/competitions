#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 55

int n, m, dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
char board[N][N];
bool seen[N][N];

int rec( int x, int y )
{
	if( x < 0 || x >= n || y < 0 || y >= m || seen[x][y] || board[x][y] != '#' ) return 0;
	seen[x][y] = true;
	int tot = 1;
	rep(d,4) tot += rec( x + dx[d], y + dy[d] );
	return tot;
}

int count()
{
	rep(i,n) rep(j,m) seen[i][j] = false;
	rep(i,n) rep(j,m) if( board[i][j] == '#' ) return rec( i, j );
	return -1;
}

int run()
{
	int tot = count();
	if( tot <= 2 ) return -1;
	rep(i,n) rep(j,m) if( board[i][j] == '#' )
	{
		board[i][j] = '.';
		if( count() + 1 < tot ) return 1;
		board[i][j] = '#';
	}
	return 2;
}

int main()
{
	scanf( "%d%d", &n, &m );
	rep(i,n) scanf( "%s", board[i] );
	printf( "%d\n", run() );
	return 0;
}
