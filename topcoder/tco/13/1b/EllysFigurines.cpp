#include <string>
#include <vector>

using namespace std;

vector<string> g;
int n, m, r, c;
bool need_row[16];

int do_cols( int mask )
{
	int ans = 0;
	for( int j = 0; j < m; )
	{
		bool need_col = false;
		for( int i = 0; i < n; i++ )
		if( !( mask & ( 1 << i ) ) && g[i][j] == 'X' )
			need_col = true;
		if( need_col ) ans++, j += c;
		else j++;
	}
	return ans;
}

int do_rows( int i, int mask )
{
	if( i >= n ) return do_cols( mask );
	int ans = do_rows( i + 1, mask );
	if( need_row[i] )
	{
		int j = i + r;
		ans = min( ans, 1 + do_rows( j, mask | ( ( 1 << j ) - ( 1 << i ) ) ) );
	}
	return ans;
}

struct EllysFigurines
{
	int getMoves( vector<string> _g, int _r, int _c )
	{
		g = _g, n = g.size(), m = g[0].size(), r = _r, c = _c;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			need_row[i] |= g[i][j] == 'X';
		return do_rows( 0, 0 );
	}
};
