#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 50
#define M 16
#define INF 123456789

int dp[1<<M][M], g[N][N], t0[M], t1[M], tc[M];

struct TravellingPurchasingMan
{
	int maxStores( int n, vs want, vs _g )
	{
		rep(i,n) rep(j,n) if( i != j ) g[i][j] = INF;
		foreach( str, _g )
		{
			int a, b, d;
			istringstream(*str) >> a >> b >> d;
			g[a][b] = g[b][a] = d;
		}

		rep(k,n) rep(i,n) rep(j,n) g[i][j] = min( g[i][j], g[i][k] + g[k][j] );

		int m = want.size();
		rep(i,1<<m) rep(j,m) dp[i][j] = INF;
		rep(i,m)
		{
			istringstream(want[i]) >> t0[i] >> t1[i] >> tc[i];
			if( g[n-1][i] <= t1[i] )
				dp[1<<i][i] = max( g[n-1][i], t0[i] ) + tc[i];
		}

		int ans = 0;
		rep(i,1<<m) rep(j,m) if( dp[i][j] < INF )
		{
			ans = max( ans, __builtin_popcount(i) );
			rep(k,m) if(!((i>>k)&1))
			{
				int start = dp[i][j] + g[j][k];
				if( start <= t1[k] )
					dp[i^(1<<k)][k] = min( dp[i^(1<<k)][k], max( start, t0[k] ) + tc[k] );
			}
		}
		return ans;
	}
};
