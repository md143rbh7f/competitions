#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

struct EelAndRabbit
{
	int getmax( vi t, vi s )
	{
		int n = s.size(), ans = 0;
		rep(i,n) t[i] += s[i];
		rep(a,n) rep(b,n)
		{
			int cnt = 0;
			rep(i,n) cnt += ( s[i] <= s[a] && s[a] <= t[i] ) || ( s[i] <= s[b] && s[b] <= t[i] );
			ans = max( ans, cnt );
		}
		return ans;
	}
};
