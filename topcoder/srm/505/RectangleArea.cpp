#include <string>
#include <vector>

using namespace std;

bool seen[100];
vector<string> g;

void dfs( int x )
{
	if( seen[x] ) return;
	seen[x] = true;
	if( x < g.size() ) for( int i = 0; i < g[0].size(); i++ ) if( g[x][i] == 'Y' ) dfs( i + g.size() );
	if( x >= g.size() ) for( int i = 0; i < g.size(); i++ ) if( g[i][x-g.size()] == 'Y' ) dfs( i );
}

struct RectangleArea
{
	int minimumQueries( vector<string> _g )
	{
		g = _g;
		int cnt = 0;
		for( int i = 0; i < g.size() + g[0].size(); i++ ) if( !seen[i] )
		{
			dfs(i);
			cnt++;
		}
		return cnt-1;
	}
};
