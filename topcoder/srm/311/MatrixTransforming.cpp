#include <string>
#include <vector>

using namespace std;

struct MatrixTransforming
{
	int minPushes( vector<string> a, vector<string> b )
	{
		int ans = 0;
		for( int i = 0; i+2 < a.size(); i++ ) for( int j = 0; j+2 < a[0].size(); j++ )
		if( a[i][j] != b[i][j] )
		{
			ans++;
			for( int k = 0; k < 3; k++ ) for( int l = 0; l < 3; l++ )
				b[i+k][j+l] = 2 * '0' + 1 - b[i+k][j+l];
		}
		return a == b ? ans : -1;
	}
};
