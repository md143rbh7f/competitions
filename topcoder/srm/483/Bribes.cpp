#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define L 17

int dp[50][1<<L];
bool ok[50][1<<L];

int bitcnt( int a )
{
	int ans = 0;
	while(a)
	{
		if(a&1) ans++;
		a >>= 1;
	}
	return ans;
}

struct Bribes
{
	int minBribes( vi infl, vi res )
	{
		int n = infl.size();
		rep(i,n) rep(j,1<<L)
		{
			int tot = 0;
			REP(k,i-8,i+9) if( k>=0 && k<n && (j>>(k-i+8))&1 ) tot += infl[k]/(1<<abs(k-i));
			ok[i][j] = tot>=res[i];
			dp[i][j] = 66;
		}
		rep(j,1<<L) dp[0][j] = bitcnt(j);
		rep(i,n-1) rep(j,1<<L) if(ok[i][j])
		{
			int nxt = j>>1;
			if(ok[i+1][nxt]) dp[i+1][nxt] = min(dp[i+1][nxt],dp[i][j]);
			nxt += 1<<(L-1);
			if(ok[i+1][nxt]) dp[i+1][nxt] = min(dp[i+1][nxt],dp[i][j]+1);
		}
		int ans = 66;
		rep(j,1<<L) if(ok[n-1][j]) ans = min(ans,dp[n-1][j]);
		return ans==66 ? -1 : ans;
	}
};
