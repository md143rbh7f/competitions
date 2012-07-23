#include <string>
#include <vector>

using namespace std;

typedef long long ll;

struct CheckerExpansion
{
	vector<string> resultAfter( ll t, ll x0, ll y0, int w, int h )
	{
		vector<string> ans( h, string( w, '.' ) );
		for( int i = 0; i < h; i++ ) for( int j = 0; j < w; j++ )
		{
			ll x = x0 + j, y = y0 + h - i - 1;
			if( ( x + y ) % 2 || x < y ) continue;
			ll u = ( x + y ) / 2, v = ( x - y ) / 2;
			if( u >= t || (~u)&v ) continue;
			ans[i][j] = u % 2 ? 'B' : 'A';
		}
		return ans;
	}
};
