#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 501

double dp[2][MAX][MAX];

struct RandomAppleEasy
{
	double theRed( vector<int> r, vector<int> g )
	{
		int n = r.size();
		dp[0][0][0] = 1;
		rep(T,n)
		{
			int t = T%2;
			rep(i,MAX) rep(j,MAX) dp[1-t][i][j] = dp[t][i][j]/2;
			rep(i,MAX-r[T]) rep(j,MAX-g[T]) dp[1-t][i+r[T]][j+g[T]] += dp[t][i][j]/2;
		}
		double ans = 0;
		rep(i,MAX) rep(j,MAX) if(i||j) ans += dp[n%2][i][j]/(1-dp[n%2][0][0])*i/(i+j);
		return ans;
	}
};
