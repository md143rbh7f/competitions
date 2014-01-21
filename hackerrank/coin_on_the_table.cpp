#include <cstdio>
#include <list>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define D 4
#define N 55

struct state
{
	int x, y, z;
	state( int _x, int _y, int _z ) : x(_x), y(_y), z(_z) {}
};

int d[N][N][2*N], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
char g[N][N], dir[] = { 'U', 'L', 'D', 'R' };

int main()
{
	int n, m, k;
	scanf( "%d%d%d", &n, &m, &k );

	rep(i,n) scanf( "%s", g[i] );

	int x0, y0;
	rep(i,n) rep(j,m) if( g[i][j] == '*' ) x0 = i, y0 = j;

	rep(i,n) rep(j,m) rep(k,n+m) d[i][j][k] = -1;
	d[0][0][0] = 0;
	list<state> q;
	q.push_back( state( 0, 0, 0 ) );

	while(!q.empty())
	{
		state u = q.front();
		q.pop_front();
		rep(i,D)
		{
			int x = u.x + dx[i], y = u.y + dy[i], z = u.z + ( dir[i] != g[u.x][u.y] );
			if( x < 0 || x >= n || y < 0 || y >= m || z >= n + m || d[x][y][z] != -1 ) continue;
			d[x][y][z] = d[u.x][u.y][u.z] + 1;
			q.push_back( state( x, y, z ) );
		}
	}

	rep(z,n+m) if( d[x0][y0][z] != -1 && d[x0][y0][z] <= k )
	{
		printf( "%d\n", z );
		return 0;
	}

	printf( "-1\n" );

	return 0;
}
