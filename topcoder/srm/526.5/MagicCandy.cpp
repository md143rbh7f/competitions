#include <cmath>

using namespace std;

struct MagicCandy
{
	int whichOne( int n )
	{
		if( n == 1 ) return 1;
		int m = whichOne( n - ( (int) sqrt( n ) ) ), ans = 0;
		for( int d = 1<<30; d > 0; d /= 2 ) if( ans + d - ( (int) sqrt( ans + d ) ) <= m ) ans += d;
		int root = (int) sqrt( ans );
		if( root * root == ans ) ans--;
		return ans;
	}
};
