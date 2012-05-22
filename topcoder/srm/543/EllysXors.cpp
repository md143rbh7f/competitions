typedef long long ll;

inline ll f( ll x )
{
	return ( ( ( x ^ 1 ) & 1 ) * x ) ^ ( ( x ^ ( x >> 1 ) ) & 1 );
}

struct EllysXors
{
	ll getXor( ll a, ll b )
	{
		return f( b ) ^ f( a - 1 );
	}
};
