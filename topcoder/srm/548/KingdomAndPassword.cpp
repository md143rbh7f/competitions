#include <set>
#include <vector>

using namespace std;

typedef long long ll;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define N 16

int dig[N];
ll pre[N+1], d[1<<N];
set<ll> best[1<<N];

struct KingdomAndPassword
{
	ll newPassword( ll old, vector<int> bad )
	{
		int n = bad.size(), m = 1<<n;

		pre[n] = old;
		for( int i = n-1; i >= 0; i-- )
			dig[i] = pre[i+1] % 10, pre[i] = pre[i+1] / 10;

		best[0].insert( 0 );
		for( int s = 0; s < m; s++ ) if( !best[s].empty() )
		{
			int len = __builtin_popcount( s );
			for( int i = 0; i < n; i++ )
			if( !( ( s >> i ) & 1 ) && dig[i] != bad[len] )
			{
				int t = s ^ (1<<i);
				foreach( x, best[s] )
				{
					ll y = 10 * (*x) + dig[i], d2 = y - pre[len+1];
					if( d2 < 0 ) d2 = -d2 - 1;
					if( best[t].empty() || d2 < d[t] )
					{
						best[t].clear();
						best[t].insert( y );
						d[t] = d2;
					}
					else if( d2 == d[t] ) best[t].insert( y );
				}
			}
		}

		if( best[m-1].empty() ) return -1;
		return *best[m-1].begin();
	}
};
