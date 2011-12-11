#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define OVER_NINE_THOUSAND 9001

int c1( vector<int> & x, int n )
{
	int best = OVER_NINE_THOUSAND;
	for( int i = 0; i < n; i++ )
	{
		int moves = 0;
		for( int j = 0; j < x.size(); j++ ) moves += abs( x[j] - i );
		if( moves < best ) best = moves;
	}
	return best;
}

int c2( vector<int> & x, int n )
{
	int best = OVER_NINE_THOUSAND;
	for( int i = 0; i + x.size() <= n; i++ )
	{
		int moves = 0;
		for( int j = 0; j < x.size(); j++ ) moves += abs( x[j] - ( i + j ) );
		if( moves < best ) best = moves;
	}
	return best;
}

struct DucksAlignment
{
	int minimumTime( vector<string> g )
	{
		int n = g.size(), m = g[0].size();
		vector<int> x, y;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( g[i][j] == 'o' )
			x.push_back( i ), y.push_back( j );
		sort( x.begin(), x.end() );
		sort( y.begin(), y.end() );
		return min( c1(x,n) + c2(y,m), c2(x,n) + c1(y,m) );
	}
};
