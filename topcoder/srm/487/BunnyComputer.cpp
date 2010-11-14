#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int dp[50][2];

struct BunnyComputer
{
	int getMaximum( vi p, int k )
	{
		k++;
		int n=p.size(), ans=0;
		rep(i,min(n,k)) for(int j=i+k;j<n;j+=k) dp[j][0]=max(dp[j-k][0],dp[j-k][1]), dp[j][1]=dp[j-k][0]+p[j]+p[j-k];
		rep(i,min(n,k)) ans+=max(dp[n-i-1][0],dp[n-i-1][1]);
		return ans;
	}
};
