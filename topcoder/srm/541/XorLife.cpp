#include <map>
#include <string>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;
typedef vector<string> grid;

map< int, map< grid, ll > > mem;
int dx[] = { -1, 1, 0, 0, 0 }, dy[] = { 0, 0, 0, -1, 1 };

ll rec( int k, grid & g )
{
	if( !g.size() || !g[0].size() ) return 0;
	if( mem.count( k ) && mem[k].count( g ) )
		return mem[k][g];

	ll & ans = mem[k][g];
	int n = g.size(), m = g[0].size();
	if( k % 2 )
	{
		grid h( n + 2, string( m + 2, 0 ) );
		rep(i,n) rep(j,m) rep(d,5) h[i+1+dx[d]][j+1+dy[d]] ^= g[i][j];
		ans = rec( k - 1, h );
	}
	else if( !k ) rep(i,n) rep(j,m) ans += g[i][j];
	else rep(a,2) rep(b,2)
	{
		int _n = ( n + 1 - a ) / 2, _m = ( m + 1 - b ) / 2;
		grid h( _n, string( _m, 0 ) );
		rep(i,_n) rep(j,_m) h[i][j] = g[2*i+a][2*j+b];
		ans += rec( k / 2, h );
	}
	return ans;
}

struct XorLife
{
	ll countAliveCells( grid g, int k )
	{
		rep(i,g.size()) rep(j,g[0].size()) g[i][j] = g[i][j] == 'o';
		return rec( k, g );
	}
};
