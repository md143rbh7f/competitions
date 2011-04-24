#include <vector>

using namespace std;

struct CarrotBoxesEasy
{
	int theIndex( vector<int> c, int k )
	{
		int best = 0;
		for( int i = 0; i < k; i++ )
		{
			best = 0;
			for( int j = 0; j < c.size(); j++ ) if( c[j] > c[best] ) best = j;
			c[best]--;
		}
		return best;
	}
};
