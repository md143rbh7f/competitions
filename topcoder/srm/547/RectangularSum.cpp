#include <vector>

using namespace std;

typedef long long ll;

struct RectangularSum
{
	ll minimalArea( int n, int m, ll s )
	{
		s *= 2;
		vector<int> f;
		for( int i = 1; i <= n || i <= m; i++ ) if( s % i == 0 ) f.push_back( i );
		ll ans = -1;
		for( int i = 0; i < f.size() && f[i] <= n; i++ )
		for( int j = 0; j < f.size() && f[j] <= m; j++ )
		{
			ll dx = f[i], dy = f[j];
			ll a = ( s / dx / dy + m * ( 1 - dx ) + 1 - dy ) / 2;
			ll x = a / m, y = a % m;
			if( 0 <= x && x + dx <= n && 0 <= y && y + dy <= m
			&& dx * dy * ( m * ( dx - 1 ) + dy - 1 + 2 * a ) == s
			&& ( ans == -1 || dx * dy < ans ) )
				ans = dx * dy;
		}
		return ans;
	}
};
