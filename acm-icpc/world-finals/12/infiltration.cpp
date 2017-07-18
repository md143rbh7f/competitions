#include <iostream>

using namespace std;

#define N 80
#define L 64
#define M 10

typedef unsigned long long ull;

struct mask
{
	ull a, b;

	inline void flip( int i )
	{
		if( i < L ) a ^= 1ull << i;
		else b ^= 1ull << ( i - L );
	}

	inline bool get( int i ) const
	{ return ( i < L ? a >> i : b >> ( i - L ) ) & 1; }

	mask( ull _a = 0, ull _b = 0 ) : a(_a), b(_b) {}
	mask( string & s ) : a(0), b(0)
	{ for( int i = 0; i < s.size(); i++ ) if( s[i] == '1' ) flip( i ); }

	inline int size() const
	{ return __builtin_popcountll( a ) + __builtin_popcountll( b ); }

	inline const mask & operator |= ( const mask & o )
	{
		a |= o.a, b |= o.b;
		return *this;
	}

	inline mask operator | ( const mask & o ) const
	{ return mask(*this) |= o; }

	inline mask operator - ( const mask & o ) const
	{ return mask( a & ~o.a, b & ~o.b ); }
};

mask g[N], seen[M];
int n, cur[M], best[M], best_sz;

void rec( int sz, int i )
{
	if( seen[sz].size() == n )
	{
		if( sz < best_sz )
		{
			best_sz = sz;
			for( int i = 0; i < sz; i++ ) best[i] = cur[i];
		}
		return;
	}
	if( sz == best_sz || i == n ) return;
	for( int & k = cur[sz] = i; k < n; k++ )
	{
		seen[sz+1] = seen[sz] | g[k];
		rec( sz + 1, k + 1 );
	}
}

bool run( int t )
{
	cin >> n;
	if( cin.fail() ) return false;
	for( int i = 0; i < n; i++ )
	{
		string s;
		cin >> s;
		g[i] = mask(s), g[i].flip( i );
	}

	best_sz = 0;
	mask greedy;
	while( greedy.size() < n )
	{
		int top = 0, hit = 0;
		for( int i = 0; i < n; i++ )
		{
			int hit2 = ( g[i] - greedy ).size();
			if( hit2 > hit ) top = i, hit = hit2;
		}
		best[best_sz++] = top, greedy |= g[top];
	}

	rec( 0, 0 );

	cout << "Case " << t << ": " << best_sz;
	for( int i = 0; i < best_sz; i++ ) cout << " " << best[i] + 1;
	cout << endl;
	return true;
}

int main()
{
	for( int t = 1; run( t ); t++ );
	return 0;
}
