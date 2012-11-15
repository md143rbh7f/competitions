#include <string>
#include <vector>

using namespace std;

#define N 55
#define M 10

bool h[N][N], v[N][N], need[M];

bool run( vector<string> & g, bool res[N][N] )
{
	bool ok = false;
	for( int i = 0; i < g.size(); i++ )
	{
		char last = 0;
		for( int j = 0; j < g[0].size(); j++ )
		{
			char c = g[i][j];
			if( c == 'A' || c == 'B' )
			{
				ok = true;
				if( !last ) last = c;
				else if( c != last ) last = 0;
				else return false;
			}
			else res[i][j] = last;
		}
		if( last ) return false;
	}
	return ok;
}

struct ToyTrain
{
	int getMinCost( vector<string> g )
	{
		int n = g.size(), m = g[0].size();
		if( !run( g, h ) ) return -1;

		vector<string> f( m, string( n, ' ' ) );
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) f[j][i] = g[i][j];
		if( !run( f, v ) ) return -1;

		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			char c = g[i][j];
			if( h[i][j] && v[j][i] ) return -1;
			if( !h[i][j] && !v[j][i] && c == 'S' ) return -1;
			if( '1' <= c && c <= '9' && ( h[i][j] || v[j][i] ) ) need[c-'0'] = true;
		}

		int ans = 0;
		for( int i = 1; i <= 9; i++ ) ans += i * need[i];
		return ans;
	}
};
