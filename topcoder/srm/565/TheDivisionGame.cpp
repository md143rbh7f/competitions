typedef long long ll;

#define N 1000005
#define P 33333
#define Q 64

int x[N], nim[N], cnt[Q];
bool isp[P];

struct TheDivisionGame
{
	ll countWinningIntervals( int l, int r )
	{
		int n = r - l + 1;
		for( int i = 0; i < n; i++ ) x[i] = i + l;

		for( int i = 2; i * i <= r; i++ ) isp[i] = true;
		for( int i = 2; i * i <= r; i++ ) if( isp[i] )
		{
			for( int j = 2 * i; (ll) j * j <= r; j += i )
				isp[j] = false;

			for( int j = ( l + i - 1 ) / i * i - l; j < n; j += i )
			while( x[j] % i == 0 )
				nim[j]++, x[j] /= i;
		}
		for( int i = 0; i < n; i++ ) if( x[i] > 1 ) nim[i]++;

		ll ans = (ll) n * ( n + 1 ) / 2;
		int cur = 0;
		cnt[0] = 1;
		for( int i = 0; i < n; i++ ) cur ^= nim[i], cnt[cur]++;
		for( int i = 0; i < Q; i++ ) ans -= (ll) cnt[i] * ( cnt[i] - 1 ) / 2;
		return ans;
	}
};
