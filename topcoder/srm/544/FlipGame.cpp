#include <string>
#include <vector>

using namespace std;

struct FlipGame
{
	int minOperations( vector<string> b )
	{
		int n = b.size(), m = b[0].size(), ans = 0;
		while(1)
		{
			int last = -1;
			for( int i = 0; i < n; i++ )
			{
				for( int j = last + 1; j < m; j++ ) if( b[i][j] == '1' ) last = j;
				for( int j = 0; j <= last; j++ ) b[i][j] = 2 * '0' + 1 - b[i][j];
			}
			if( last == -1 ) break;
			ans++;
		}
		return ans;
	}
};
