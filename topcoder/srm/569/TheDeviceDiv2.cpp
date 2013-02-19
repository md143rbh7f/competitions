#include <string>
#include <vector>
 
using namespace std;
 
struct TheDeviceDiv2
{
	string identify( vector<string> vs )
	{
		int n = vs.size(), b = vs[0].size(), c[2];
		for( int i = 0; i < b; i++ )
		{
			c[0] = c[1] = 0;
			for( int j = 0; j < n; j++ ) c[vs[j][i]-'0']++;
			if( c[0] < 1 || c[1] < 2 ) return "NO";
		}
		return "YES";
	}
};
