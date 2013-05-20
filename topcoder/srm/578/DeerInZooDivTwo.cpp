#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct DeerInZooDivTwo
{
	vi getminmax( int n, int k )
	{
		vi ans;
		ans.push_back( max( n - k, 0 ) );
		ans.push_back( n - ( k + 1 ) / 2 );
		return ans;
	}
};
