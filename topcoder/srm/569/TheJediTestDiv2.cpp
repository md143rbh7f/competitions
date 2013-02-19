#include <algorithm>
#include <vector>

using namespace std;

struct TheJediTestDiv2
{
	int countSupervisors( vector<int> s, int yoda, int jedi )
	{
		int n = s.size(), ans = 123456789;
		for( int i = 0; i < n; i++ )
		{
			int need = ( max( s[i] - yoda, 0 ) + jedi - 1 ) / jedi;
			for( int j = 0; j < n; j++ ) if( j != i )
				need += ( s[j] + jedi - 1 ) / jedi;
			ans = min( ans, need );
		}
		return ans;
	}
};
