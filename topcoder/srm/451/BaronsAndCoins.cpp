#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAXN 51
#define MAXD 10001

int dp[MAXN][MAXD];
vector<pii> c;

struct BaronsAndCoins
{
	int getMaximum( vi x, vi y )
	{
		int n = x.size(), ans = 0;
		c.push_back(mp(0,0));
		rep(i,n) c.push_back(mp(y[i],x[i]));
		sort(c.begin(),c.end());
		n++;
		rep(i,n) rep(d,MAXD) dp[i][d] = -1;
		dp[0][0] = 0;
		rep(i,n) rep(d,MAXD) if(dp[i][d]!=-1) REP(j,i+1,n)
		{
			int dy = c[j].first-c[i].first;
			if(dy>0 && c[j].second>=c[i].second+dy*d+dy*(dy+1)/2 )
			{
				int mind = (c[j].second-c[i].second+dy*(dy-1)/2+dy-1)/dy;
				dp[j][mind] = max(dp[j][mind],dp[i][d]+1);
			}
		}
		rep(i,n) rep(d,MAXD) ans = max(ans,dp[i][d]);
		return ans;
	}
};
