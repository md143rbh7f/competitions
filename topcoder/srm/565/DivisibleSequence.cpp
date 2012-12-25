typedef long long ll;

#define MOD 1000000009
#define M(x) ((x)%MOD)
#define N 32

ll c[N];

ll mod_pow( ll n, ll p )
{
	if( !p ) return 1;
	return M( ( p % 2 ? n : 1 ) * mod_pow( M( n * n ), p / 2 ) );
}

struct DivisibleSequence
{
	int count( int n, int m )
	{
		c[0] = 1;
		for( int i = 1; i < N; i++ )
			c[i] = M( c[i-1] * M( ( m + i - 1 ) * mod_pow( i, MOD - 2 ) ) );

		ll ans = 1;
		for( int p = 2; p * p <= n; p++ ) if( n % p == 0 )
		{
			int e = 0;
			while( n % p == 0 ) e++, n /= p;
			ans = M( ans * c[e] );
		}
		if( n > 1 ) ans = M( ans * c[1] );
		return ans;
	}
};
