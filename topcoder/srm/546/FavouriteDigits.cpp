#include <algorithm>

using namespace std;

typedef long long ll;

#define L 19

ll ten[L], one[L];
int dig[L];

struct FavouriteDigits
{
	ll findNext( ll n, int d0, int c0, int d1, int c1 )
	{
		ten[0] = 1;
		for( int i = 1; i < L; i++ ) ten[i] = 10 * ten[i-1], one[i] = 10 * one[i-1] + 1;

		if( d0 > d1 ) swap( d0, d1 ), swap( c0, c1 );

		n--;
		int len = 0;
		for( ll tmp = n; tmp; tmp /= 10 ) dig[len++] = tmp % 10;

		ll ans = 0, pre = 0;
		int h0 = c0, h1 = c1;
		for( int i = L-1; i >= 0; i-- )
		{
			pre *= 10;
			for( int d = 9; d > dig[i]; d-- )
			{
				int k0 = max( 0, h0 - ( d == d0 ) ), k1 = max( 0, h1 - ( d == d1 ) );
				if( k0 + k1 > i ) continue;
				ans = ten[i] * ( pre + d ) + ten[k1] * one[k0] * d0 + one[k1] * d1;
			}
			pre += dig[i];
			if( i < len ) h0 -= dig[i] == d0, h1 -= dig[i] == d1;
		}

		return ans;
	}
};
