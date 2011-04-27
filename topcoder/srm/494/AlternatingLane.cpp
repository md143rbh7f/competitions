#include <vector>

using namespace std;

struct AlternatingLane
{
	double expectedBeauty( vector<int> l, vector<int> h )
	{
		double ans = 0;
		for( int i = 1; i < l.size(); i++ )
		{
			int a = l[i-1], b = h[i-1], c = l[i], d = h[i];
			for( int j = c; j <= d; j++ )
			{
				double plus_ungood = 0;
				if( j < a ) plus_ungood = 0.5 * ( a + b ) - j;
				else if( j > b ) plus_ungood = j - 0.5 * ( a + b );
				else plus_ungood = ( 0.5 * ( j - a ) * ( j - a + 1 ) + 0.5 * ( b - j ) * ( b - j + 1 ) ) / ( b - a + 1 );
				ans += plus_ungood / ( d - c + 1 );
			}
		}
		return ans;
	}
};
