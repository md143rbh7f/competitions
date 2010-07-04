#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int dp[1<<16], INF = 2000000001;

struct SquaresCovering
{
	int minCost( vi x, vi y, vi c, vi l )
	{
		int n = x.size(), m = c.size(), N = 1<<n;
		REP(i,1,N)
		{
			int xmin = INF, ymin = INF, xmax = -1, ymax = -1;
			rep(j,n) if((i>>j)&1) xmin = min(xmin,x[j]), ymin = min(ymin,y[j]), xmax = max(xmax,x[j]), ymax = max(ymax,y[j]);
			int s = max(xmax-xmin,ymax-ymin);
			dp[i] = INF;
			rep(j,m) if(l[j]>=s) dp[i] = min(dp[i],c[j]);
		}
		REP(i,1,N) for( int j = i; j>0; j=i&(j-1) ) if( dp[j]<INF && dp[i-j]<INF ) dp[i] = min( dp[i], dp[j]+dp[i-j] );
		return dp[N-1];
	}
};
