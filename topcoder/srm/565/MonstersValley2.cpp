#include <vector>

using namespace std;

struct MonstersValley2
{
	int minimumPrice( vector<int> u, vector<int> c )
	{
		int n = u.size(), ans = 9001;
		for( int i = 0; i < 1<<n; i++ )
		{
			long long v = 0;
			int cost = 0;
			for( int j = 0; j < n; j++ )
			{
				if( ( i >> j ) & 1 ) v += u[j], cost += c[j];
				else if( v < u[j] )
				{
					cost = -1;
					break;
				}
			}
			if( cost != -1 && cost < ans ) ans = cost;
		}
		return ans;
	}
};
