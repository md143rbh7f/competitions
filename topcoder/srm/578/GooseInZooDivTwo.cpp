#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 55

vs g;
int d, n, m;
bool seen[N][N];

void dfs( int x, int y )
{
	seen[x][y] = true;
	REP(i,max(x-d,0),min(x+d+1,n)) REP(j,max(y-d,0),min(y+d+1,m))
	if( g[i][j] == 'v' && !seen[i][j] && abs( i - x ) + abs( j - y ) <= d )
		dfs( i, j );
}

struct GooseInZooDivTwo
{
	int count( vs _g, int _d )
	{
		g = _g, d = _d, n = g.size(), m = g[0].size();
		int nc = 0;
		rep(i,n) rep(j,m) if( g[i][j] == 'v' && !seen[i][j] )
			nc++, dfs( i, j );
		int ans = 1;
		while( nc-- ) ans = ( 2 * ans ) % 1000000007;
		return ans - 1;
	}
};
