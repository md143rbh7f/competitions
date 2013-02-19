#include <vector>

using namespace std;

typedef long long ll;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define N 55

ll ways[N];
vector<int> g[N];

ll rec( int u, int v )
{
	ways[v] = 1;
	foreach( w, g[v] ) if( *w != u )
		ways[v] *= rec( v, *w ) + 1;
	return ways[v];
}

struct CentaurCompanyDiv2
{
	ll count( vector<int> a, vector<int> b )
	{
		int n = a.size() + 1;
		for( int i = 0; i < n - 1; i++ )
			g[a[i]].push_back( b[i] ), g[b[i]].push_back( a[i] );
		rec( 0, 1 );
		ll ans = 1;
		for( int i = 1; i <= n; i++ ) ans += ways[i];
		return ans;
	}
};
