#include <vector>

using namespace std;

struct PointErasingTwo
{
	int getMaximum( vector<int> y )
	{
		int n = y.size(), best = 0;
		for( int i = 0; i < n; i++ )
		for( int j = i+2; j < n; j++ )
		{
			int cnt = 0, a = y[i], b = y[j];
			if( a > b )
			{
				int tmp = a;
				a = b;
				b = tmp;
			}
			for( int k = i+1; k < j; k++ ) if( a < y[k] && y[k] < b ) cnt++;
			if( cnt > best ) best = cnt;
		}
		return best;
	}
};
