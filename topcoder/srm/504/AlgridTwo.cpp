#include <string>
#include <vector>

using namespace std;

struct AlgridTwo
{
	int makeProgram( vector<string> g )
	{
		int n = g.size(), m = g[0].size(), ans = 1;
		for( int i = n-2; i >= 0; i-- ) for( int j = m-2; j >= 0; j-- )
		{
			if( g[i][j]=='B' && g[i][j+1]=='B' )
			{
				char tmp = g[i+1][j];
				g[i+1][j] = g[i+1][j+1];
				g[i+1][j+1] = tmp;
			}
			else if( g[i][j]=='B' && g[i][j+1]=='W' )
			{
				if( g[i+1][j]=='W' || g[i+1][j+1]=='W' ) return 0;
				g[i+1][j] = g[i+1][j+1] = '.';
			}
			else if( g[i][j]=='W' && g[i][j+1]=='B' )
			{
				if( g[i+1][j]=='B' || g[i+1][j+1]=='B' ) return 0;
				g[i+1][j] = g[i+1][j+1] = '.';
			}
		}
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( g[i][j]=='.' ) ans = ( ans * 2 ) % 1000000007;
		return ans;
	}
};
