#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 10
#define POW 2501

bool odd[N][N], even[N][N];
int MOD = 1000000007, other[N][N];
long long dp[N][1<<N], pow4[POW], pow5[POW];

struct MagicalGirlLevelTwoDivOne
{
	int theCount( vector<string> grid, int n, int m )
	{
		pow4[0] = pow5[0] = 1;
		REP(i,1,POW) pow4[i] = ( pow4[i-1] * 4 ) % MOD, pow5[i] = ( pow5[i-1] * 5 ) % MOD;
		rep(I,grid.size()) rep(J,grid[0].size())
		{
			int i = I%n, j = J%m;
			if( grid[I][J] == '.' ) other[i][j]++;
			else if( ( grid[I][J] - '0' ) % 2 ) odd[i][j] = true;
			else even[i][j] = true;
		}
		rep(i,n) rep(j,m) if( odd[i][j] && even[i][j] ) return 0;
		rep(i,n) rep(mask,1<<m) if( __builtin_popcount(mask)%2 )
		{
			bool ok = true;
			rep(j,m) if( ( ((mask>>j)&1) && even[i][j] ) || !((mask>>j)&1) && odd[i][j] ) ok = false;
			if(!ok) continue;
			long long cnt = 1;
			rep(j,m)
			{
				if((mask>>j)&1) cnt = ( cnt * pow5[other[i][j]] ) % MOD;
				else cnt = ( cnt * pow4[other[i][j]] ) % MOD;
			}
			if(i) rep(pmask,1<<m) dp[i][pmask^mask] = ( dp[i][pmask^mask] + ( cnt * dp[i-1][pmask] ) % MOD ) % MOD;
			else dp[i][mask] = cnt;
		}
		return dp[n-1][(1<<m)-1];
	}
};
