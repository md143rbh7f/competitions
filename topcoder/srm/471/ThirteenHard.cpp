#include <string>
#include <vector>

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int dp[1<<13][25][13], d[25][25], INF = 111111111;

class ThirteenHard
{
	public:
	int calcTime( vector<string> g )
	{
		int n = g.size();
		rep(i,n) rep(j,n)
		{
			char c = g[i][j];
			if( c=='#' ) d[i][j] = INF;
			if( c>='A' && c<='Z' ) d[i][j] = c-'A'+1;
			if( c>='a' && c<='z' ) d[i][j] = c-'a'+27;
		}
		rep(i,1<<13) rep(j,n) rep(m,13) dp[i][j][m] = INF;
		dp[1][0][0] = 0;
		rep(i,1<<13) rep(j,n) rep(m,13) if(dp[i][j][m]!=INF) rep(J,n) if(d[j][J]!=INF)
		{
			int tot = dp[i][j][m]+d[j][J], M = tot%13;
			if( (i>>M)&1 ) continue;
			int I = i | 1<<M;
			if( tot < dp[I][J][M] ) dp[I][J][M] = tot;
		}
		int ans = INF;
		rep(i,1<<13) rep(m,13) if( dp[i][n-1][m]<ans ) ans = dp[i][n-1][m];
		if( ans==INF ) return -1;
		return ans;
	}
};
