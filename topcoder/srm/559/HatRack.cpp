#include <vector>

using namespace std;

typedef long long ll;
#define N 55

vector<int> g[N];
int mem_size[N][N];
ll mem_ways[N][N];

inline bool full( int i ) { return !( i & ( i + 1 ) ); }

int size( int v, int p )
{
	int & ans = mem_size[v][p];
	if( ans != -1 ) return ans;
	ans = 1;
	for( int i = 0; i < g[v].size(); i++ ) if( g[v][i] != p ) ans += size( g[v][i], v );
	return ans;
}

ll ways( int v, int p )
{
	ll & ans = mem_ways[v][p];
	if( ans != -1 ) return ans;

	vector<int> c;
	for( int i = 0; i < g[v].size(); i++ ) if( g[v][i] != p ) c.push_back( g[v][i] );

	ans = 0;
	if( c.size() == 0 || ( c.size() == 1 && size( c[0], v ) == 1 ) ) ans = 1;
	if( c.size() == 2 )
	{
		int l = c[0], r = c[1], sl = size( l, v ), sr = size( r, v );
		if( sl < sr )
		{
			l ^= r, r ^= l, l ^= r;
			sl ^= sr, sr ^= sl, sl ^= sr;
		}
		if( full( sl ) || full( sr ) )
		{
			if( sl <= 2 * sr + 1 ) ans = ways( l, v ) * ways( r, v );
			if( sl == sr ) ans *= 2;
		}
	}
	return ans;
}

struct HatRack
{
	ll countWays( vector<int> a, vector<int> b )
	{
		for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ ) mem_ways[i][j] = mem_size[i][j] = -1;

		int n = a.size() + 1;
		for( int i = 0; i < n - 1; i++ )
		{
			int x = a[i], y = b[i];
			x--, y--;
			g[x].push_back(y), g[y].push_back(x);
		}

		ll ans = 0;
		for( int i = 0; i < n; i++ ) ans += ways( i, i );
		return ans;
	}
};
