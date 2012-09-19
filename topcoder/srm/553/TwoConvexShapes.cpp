#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define N 55
#define MOD 1000000007
#define ok(i,j) ( x[i][j] == x[i][m] && y[i][j] == 0 )
#define add(i,j) i = ( i + j ) % MOD

int n, m, inc[N][N], dec[N][N], eq[N][N], b[N][N], w[N][N];

int count( int x[N][N], int y[N][N] )
{
	memset( inc, 0, sizeof(inc) );
	memset( dec, 0, sizeof(dec) );
	memset( eq, 0, sizeof(eq) );

	for( int j = 0; j <= m; j++ ) inc[0][j] = dec[0][j] = eq[0][j] = ok( 0, j );
	for( int i = 1; i < n; i++ ) for( int j = 0; j <= m; j++ ) if( ok( i, j ) )
	{
		for( int k = 0; k <= j; k++ ) add( inc[i][j], inc[i-1][k] );
		for( int k = j; k <= m; k++ ) add( dec[i][j], dec[i-1][k] );
		eq[i][j] = eq[i-1][j];
	}

	int ans = 0;
	for( int j = 0; j <= m; j++ )
	{
		add( ans, inc[n-1][j] );
		add( ans, dec[n-1][j] );
		add( ans, MOD - eq[n-1][j] );
	}
	return ans;
}

struct TwoConvexShapes
{
	int countWays( vector<string> g )
	{
		n = g.size(), m = g[0].size();

		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			b[i][j+1] = b[i][j] + ( g[i][j] == 'B' );
			w[i][j+1] = w[i][j] + ( g[i][j] == 'W' );
		}

		int ans = 0;
		add( ans, count( b, w ) );
		add( ans, count( w, b ) );
		for( int i = 1; i < n; i++ )
		{
			b[i][m] += b[i-1][m];
			w[i][m] += w[i-1][m];
		}
		for( int i = 0; i < n; i++ )
		{
			if( b[i][m] == b[n-1][m] && w[i][m] == 0 ) add( ans, MOD - 1 );
			if( w[i][m] == w[n-1][m] && b[i][m] == 0 ) add( ans, MOD - 1 );
		}
		return ans;
	}
};
