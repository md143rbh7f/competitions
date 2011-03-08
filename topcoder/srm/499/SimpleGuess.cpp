#include <vector>

using namespace std;

struct SimpleGuess
{
	int getMaximum( vector<int> hints )
	{
		int ans = 0;
		for( int i = 0; i < hints.size(); i++ ) for( int j = 0; j < hints.size(); j++ ) if( hints[i]%2 == hints[j]%2 )
		{
			int x = (hints[i]+hints[j])/2, y = (hints[i]-hints[j])/2;
			if( x > 0 && y > 0 && x*y > ans ) ans = x*y;
		}
		return ans;
	}
};
