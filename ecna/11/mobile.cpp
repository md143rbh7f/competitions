#include <cstdio>

using namespace std;

typedef long long ll;
#define N 200

char type_l[2], type_r[2];
int dl[N], dr[N], l[N], r[N], n, min_x, min_w;
ll w[N];
bool is_root[N];

ll gcd( ll a, ll b )
{
	while( b != 0 )
	{
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}

ll rec( int x )
{
	if( x >= n ) return 1;
	ll wl = rec( l[x] ), wr = rec( r[x] );
	ll g = gcd( wl * dl[x], wr * dr[x] );
	ll cl = wr * dr[x] / g, cr = wl * dl[x] / g;
	return cl * wl + cr * wr;
}

void assign( int x, ll weight )
{
	w[x] = weight;
	if( x >= n ) return;
	assign( l[x], weight * dr[x] / ( dl[x] + dr[x] ) );
	assign( r[x], weight * dl[x] / ( dl[x] + dr[x] ) );
}

int main()
{
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d", &n );
		if(!n) break;

		for( int i = 0; i < N; i++ ) is_root[i] = true;

		for( int i = 0; i < n; i++ )
		{
			scanf( "%d%d%s%s%d%d", &dl[i], &dr[i], type_l, type_r, &l[i], &r[i] );
			l[i]--, r[i]--;
			if( type_l[0] == 'W' ) l[i] += n;
			if( type_r[0] == 'W' ) r[i] += n;
			is_root[l[i]] = false;
			is_root[r[i]] = false;
		}
		scanf( "%d%d", &min_x, &min_w );
		min_x = min_x - 1 + n;

		int root = 0;
		for( ; !is_root[root]; root++ );
		ll root_weight = rec( root );
		assign( root, root_weight );
		if( w[min_x] < min_w ) root_weight *= ( min_w + w[min_x] - 1 ) / w[min_x];
		printf( "Case %d: %lld\n", case_num, root_weight );
	}
	return 0;
}
