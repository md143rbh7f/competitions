#include "stdio.h"

#define T (1<<17)
#define MOD 1000003

int n, q, cmd, a, b, v, d[T], p[T];
long long fac[MOD], base[2*T], power[2*T], prod[2*T], stale[2*T], ans_pow, ans_prod;

long long mult( long long a, long long b )
{
	return ( a * b ) % MOD;
}

long long mod_pow( long long b, long long x )
{
	if( x == 0 ) return 1;
	return mult( x % 2 ? b : 1, mod_pow( mult( b, b ), x / 2 ) );
}

void init( int x, int i, int j )
{
	if( i + 1 == j )
	{
		base[x] = d[i], power[x] = p[i], prod[x] = mod_pow( d[i], p[i] );
		return;
	}

	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	init( y, i, k ), init( z, k, j );
	base[x] = mult( base[y], base[z] );
	power[x] = power[y] + power[z];
	prod[x] = mult( prod[y], prod[z] );
}

void push_update( int x, int p, int sz )
{
	prod[x] = mult( prod[x], mod_pow( base[x], p ) );
	power[x] += p * sz;
	stale[x] += p;
}

void query( int x, int i, int j )
{
	if( a >= j || i >= b ) return;
	if( a <= i && j <= b )
	{
		if( cmd ) push_update( x, v, j - i );
		else ans_pow += power[x], ans_prod = mult( ans_prod, prod[x] );
		return;
	}

	int y = 2*x, z = 2*x+1, k = (i+j+1)/2;
	if( stale[x] )
	{
		push_update( y, stale[x], k - i );
		push_update( z, stale[x], j - k );
		stale[x] = 0;
	}
	query( y, i, k ), query( z, k, j );

	power[x] = power[y] + power[z];
	prod[x] = mult( prod[y], prod[z] );
}

int main()
{
	int i;

	fac[0] = 1;
	for( i = 1; i < MOD; i++ ) fac[i] = mult( i, fac[i-1] );

	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) scanf( "%d%d%d", &q, &d[i], &p[i] );
	init( 1, 0, n );

	scanf( "%d", &q );
	while( q-- )
	{
		scanf( "%d%d%d", &cmd, &a, &b );
		a--;
		if( cmd ) scanf( "%d", &v );
		else ans_pow = 0, ans_prod = 1;
		query( 1, 0, n );
		if( !cmd )
		{
			ans_prod = ans_pow < MOD ? mult( ans_prod, fac[ans_pow] ) : 0;
			printf( "%lld %lld\n", ans_pow, ans_prod );
		}
	}

	return 0;
}
