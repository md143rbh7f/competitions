#include <string>
#include <vector>

using namespace std;

struct HouseBuilding
{
	int getMinimum( vector<string> h )
	{
		int n = h.size(), m = h[0].size(), ans = 123456789;
		for( int x = 0; x < 9; x++ )
		{
			int cost = 0;
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			{
				int y = h[i][j] - '0';
				if( y < x ) cost += x - y;
				if( y > x + 1 ) cost += y - ( x + 1 );
			}
			if( cost < ans ) ans = cost;
		}
		return ans;
	}
};
