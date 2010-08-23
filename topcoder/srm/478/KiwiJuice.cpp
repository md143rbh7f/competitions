#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int dp[1<<15];

struct KiwiJuice
{
	int theProfit( int c, vi b, vi p )
	{
		int n = b.size(), N = 1<<n;
		rep(i,N)
		{
			int sum = 0, cnt = 0;
			rep(j,n) if((i>>j)&1) sum += b[j], cnt++;
			dp[i] = sum/c*p[c] + (cnt-sum/c-1)*p[0] + p[sum%c];
			for( int j = i; j > 0; j = (j-1)&i ) dp[i] = max( dp[i], dp[j]+dp[i-j] );
		}
		return dp[(1<<n)-1];
	}
};
