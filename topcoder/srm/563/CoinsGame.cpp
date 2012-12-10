#include <list>
#include <string>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define MOD 1000000009
#define N 1605
#define D 4

vector<string> g;
vector<int> prev[N][D];
int w, h, n, next[N][D], dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
bool good[N], distinct[N][N], seen[N];

void compute_prev_next()
{
	for( int x = 0; x < w; x++ ) for( int y = 0; y < h; y++ )
	if( g[x][y] != '#' )
	{
		int s = x * h + y;
		good[s] = true;
		for( int d = 0; d < D; d++ )
		{
			int xx = x + dx[d], yy = y + dy[d], t = xx * h + yy;
			if( xx < 0 || xx >= w || yy < 0 || yy >= h ) t = -1;
			else if( g[xx][yy] == '#' ) t = s;
			if( t != -1 ) prev[t][d].push_back( s );
			next[s][d] = t;
		}
	}
}

void compute_distinct()
{
	list<int> q0, q1;
	for( int s0 = 0; s0 < n; s0++ ) if( good[s0] )
	for( int s1 = 0; s1 < n; s1++ ) if( good[s1] )
	{
		bool diff = false;
		for( int d = 0; d < D; d++ )
			diff |= ( next[s0][d] == -1 ) ^ ( next[s1][d] == -1 );
		if( diff )
			q0.push_back( s0 ), q1.push_back( s1 ), distinct[s0][s1] = true;
	}
	
	while( !q0.empty() )
	{
		int s0 = q0.front(), s1 = q1.front();
		q0.pop_front(), q1.pop_front();
		for( int d = 0; d < D; d++ )
		foreach( t0, prev[s0][d] ) foreach( t1, prev[s1][d] )
		if( !distinct[*t0][*t1] )
			q0.push_back( *t0 ), q1.push_back( *t1 ), distinct[*t0][*t1] = true;
	}
}

struct CoinsGame
{
	int ways( vector<string> _g )
	{
		g = _g, w = g.size(), h = g[0].size(), n = w * h;

		compute_prev_next();
		compute_distinct();
		
		long long ans = 1;
		for( int s = 0; s < n; s++ ) if( good[s] ) ans = ( 2 * ans ) % MOD;
		ans = ( ans - 1 + MOD ) % MOD;
		for( int s = 0; s < n; s++ )
		if( good[s] && !seen[s] )
		{
			long long tot = 1;
			for( int t = 0; t < n; t++ )
			if( good[t] && !distinct[s][t] )
				seen[t] = true, tot = ( 2 * tot ) % MOD;
			ans = ( ans - tot + 1 + MOD ) % MOD;
		}
		return ans;
	}
};
