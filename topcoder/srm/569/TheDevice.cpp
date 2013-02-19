#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
struct TheDevice
{
	int minimumAdditional( vector<string> vs )
	{
		int n = vs.size(), b = vs[0].size(), ans = 0, c[2];
		for( int i = 0; i < b; i++ )
		{
			c[0] = c[1] = 0;
			for( int j = 0; j < n; j++ ) c[vs[j][i]-'0']++;
			ans = max( ans, max( 0, 1 - c[0] ) + max( 0, 2 - c[1] ) );
		}
		return ans;
	}
};
