#include <algorithm>
#include <vector>

using namespace std;

struct TheJediTest
{
	int minimumSupervisors( vector<int> s, int k )
	{
		int n = s.size(), ans = 0;
		vector<int> t(n);
		for( int i = 0; i + 1 < n; i++ )
		{
			int tot = s[i] + t[i], up = tot % k, down = min( k - up, s[i+1] );
			if( s[i] >= up ) s[i] -= up, t[i+1] += up;
			else t[i] += down, s[i+1] -= down;
		}
		for( int i = 0; i < n; i++ ) ans += ( s[i] + t[i] + k - 1 ) / k;
		return ans;
	}
};
