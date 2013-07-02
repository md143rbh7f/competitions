#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define INF 1234567
#define N 55

int ans[N][N], s[N][N];

struct WallGameDiv2
{
	int play( vs g )
	{
		int n = g.size(), m = g[0].size();
		rep(i,n) rep(j,m) s[i][j+1] = s[i][j] + g[i][j] - '0';
		rep(i,n) rep(j,m) ans[i][j] = -INF;
		rep(j,m) if( g[n-1][j] != 'x' ) ans[n-1][j] = g[n-1][j] - '0';
		for( int i = n - 2; i >= 0; i-- ) rep(j,m) if( g[i][j] != 'x' )
		{
			for( int k = j; k >= 0 && g[i][k] != 'x'; k-- )
				acc( max, ans[i][j], ans[i+1][k] + s[i][j+1] - s[i][k] );
			for( int k = j; k < m && g[i][k] != 'x'; k++ )
				acc( max, ans[i][j], ans[i+1][k] + s[i][k+1] - s[i][j] );
		}
		return ans[0][0];
	}
};
