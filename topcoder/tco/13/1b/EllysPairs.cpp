#include <algorithm>
#include <vector>

using namespace std;

#define INF 123456789

struct EllysPairs
{
	int getDifference( vector<int> x )
	{
		int n = x.size(), lo = INF, hi = -INF;
		sort( x.begin(), x.end() );
		for( int i = 0; i < n / 2; i++ )
		{
			int s = x[i] + x[n-i-1];
			lo = min( lo, s ), hi = max( hi, s );
		}
		return hi - lo;
	}
};
