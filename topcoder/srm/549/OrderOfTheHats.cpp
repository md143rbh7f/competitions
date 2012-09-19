#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define N 20

int best[1<<N], h[N];

struct OrderOfTheHats
{
	int minChanged( vector<string> g )
	{
		int n = g.size(), m = 1<<n;
		rep(i,n) rep(j,n) if( g[i][j] == 'Y' ) h[j] ^= 1<<i;
		REP(s,1,m)
		{
			best[s] = 111111111;
			rep(i,n) if( s & ( 1 << i ) )
				best[s] = min( best[s], __builtin_popcount( h[i] & s ) + best[s^(1<<i)] );
		}
		return best[m-1];
	}
};
