#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define BAD 123456789
#define N 205

#define MEMO(arr) \
	if( !ok( x, y ) ) return 0; \
	int & ans = arr[i][j][x][y]; \
	if( ans ) return ans;

int n, m, d[] = { -1, 1 }, g[N][N], H[2][2][N][N], C[2][2][N][N], L[2][2][N][N];

inline bool ok( int x, int y ) { return x >= 0 && y >= 0 && x < n && y < m; }

int height( int i, int j, int x, int y )
{
	MEMO(H);
	int u = height( i, j, x + d[i], y ), v = height( i, j, x, y + d[j] );
	int w = g[x][y];
	if( w ) ans = w > u && w > v ? w : BAD;
	else ans = min( max( u, v ) + 1, BAD );
	return ans;
}

int corner( int i, int j, int x, int y )
{
	MEMO(C);
	ans = min(
		height( i, j, x + d[i], y + d[j] )
		+ corner( i, j, x + d[i], y )
		+ corner( i, j, x, y + d[j] )
		- corner( i, j, x + d[i], y + d[j] ),
		BAD
	);
	return ans;
}

int line( int i, int j, int x, int y )
{
	MEMO(L);
	x += ( !i ) * d[j], y += i * d[j];
	rep(k,2) ans = max( ans, height( i ? k : j, i ? j : k, x, y ) );
	ans += line( i, j, x, y );
	return ans = min( ans, BAD );
}

int get( int x, int y )
{
	int ans = 0;
	rep(i,2) rep(j,2) ans = max( ans, height( i, j, x, y ) );
	rep(i,2) rep(j,2) ans += corner( i, j, x, y ) + line( i, j, x, y );
	return min( ans, BAD );
}

struct TheMountain
{
	int minSum( int _n, int _m, vi r, vi c, vi v )
	{
		n = _n, m = _m;
		rep(i,r.size()) g[r[i]][c[i]] = v[i];
		int ans = BAD;
		rep(x,n) rep(y,m) ans = min( ans, get( x, y ) );
		return ans < BAD ? ans : -1;
	}
};
