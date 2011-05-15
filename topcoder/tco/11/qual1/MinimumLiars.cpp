#include <vector>

using namespace std;

struct MinimumLiars
{
	int getMinimum( vector<int> c )
	{
		for( int i = 0; i <= c.size(); i++ )
		{
			int cnt = 0;
			for( int j = 0; j < c.size(); j++ ) if( c[j] > i ) cnt++;
			if( cnt == i ) return i;
		}
		return -1;
	}
};

