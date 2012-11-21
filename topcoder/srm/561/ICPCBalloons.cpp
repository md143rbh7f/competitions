#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define get(a,i) ((i)<(a).size()?(a)[(i)]:0)

vector<int> haves[2], needs[2];

int work( vector<int> & have, vector<int> & need )
{
	int cost = 0, diff = 0;
	rep(i,max(have.size(),need.size()))
	{
		int a = get( have, i ), b = get( need, i );
		diff += a - b;
		if( b > a ) cost += b - a;
	}
	return diff >= 0 ? cost : -1;
}

struct ICPCBalloons
{
	int minRepaintings( vector<int> have, string sz, vector<int> need )
	{
		rep(i,have.size()) haves[sz[i]=='L'].push_back( have[i] );
		rep(b,2) sort( haves[b].begin(), haves[b].end(), greater<int>() );
		sort( need.begin(), need.end(), greater<int>() );

		int n = need.size(), ans = -1;
		rep(s,1<<n)
		{
			rep(b,2) needs[b].clear();
			rep(i,n) needs[1&(s>>i)].push_back( need[i] );

			bool ok = true;
			int cost = 0;
			rep(b,2)
			{
				int x = work( haves[b], needs[b] );
				if( x == -1 ) ok = false;
				else cost += x;
			}
			if( ok && ( cost < ans || ans == -1 ) ) ans = cost;
		}
		return ans;
	}
};
