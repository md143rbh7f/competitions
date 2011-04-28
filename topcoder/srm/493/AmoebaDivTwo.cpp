#include <string>
#include <vector>

using namespace std;

struct AmoebaDivTwo
{
	int count( vector<string> g, int l )
	{
		int n = g.size(), m = g[0].size(), cnt = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			if( i + l <= n )
			{
				bool ok = true;
				for( int k = 0; k < l; k++ ) if( g[i+k][j] == 'M' ) ok = false;
				if(ok) cnt++;
			}
			if( l > 1 && j + l <= m )
			{
				bool ok = true;
				for( int k = 0; k < l; k++ ) if( g[i][j+k] == 'M' ) ok = false;
				if(ok) cnt++;
			}
		}
		return cnt;
	}
};
