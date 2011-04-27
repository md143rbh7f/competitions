#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

struct Algrid
{
	vs makeProgram( vs g )
	{
		int n = g.size(), m = g[0].size();
		vs ans(n);
		for( int i = n-1; i > 0; i-- )
		{
			ans[i] = g[i];
			for( int j = m-2; j >= 0; j-- )
			{
				if( g[i-1][j]=='B' && g[i-1][j+1]=='B' ) swap( ans[i][j], ans[i][j+1] );
				else if( g[i-1][j]=='B' && g[i-1][j+1]=='W' )
				{
					if( ans[i][j]=='W' || ans[i][j+1]=='W' ) return vs();
					ans[i][j] = ans[i][j+1] = '.';
				}
				else if( g[i-1][j]=='W' && g[i-1][j+1]=='B' )
				{
					if( ans[i][j]=='B' || ans[i][j+1]=='B' ) return vs();
					ans[i][j] = ans[i][j+1] = '.';
				}
			}
			for( int j = 0; j < m; j++ ) if( ans[i][j]=='.' ) ans[i][j] = 'B';
		}
		ans[0] = g[0];
		return ans;
	}
};
