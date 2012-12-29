typedef long long ll;

ll gcd( ll a, ll b )
{
	while( b )
	{
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

struct FractionInDifferentBases
{
	ll getNumberOfGoodBases( ll p, ll q, ll a, ll b )
	{
		q /= gcd( p, q );
		ll r = 1;
		for( ll x = 2; x * x <= q; x++ ) if( q % x == 0 )
		{
			r *= x;
			while( q % x == 0 ) q /= x;
		}
		if( q > 1 ) r *= q;
		a--;
		return b - b / r - a + a / r;
	}
};
