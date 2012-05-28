#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

#define N 100005

struct pt { ll x[2], d; };

pt pts[N];
int n, c;

bool comp( const pt & a, const pt & b ) { return a.x[c] < b.x[c]; }

int main()
{
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ )
	{
		ll u, v;
		scanf( "%lld%lld", &u, &v );
		pts[i].x[0] = u + v, pts[i].x[1] = u - v;
	}

	for( c = 0; c < 2; c++ )
	{
		sort( pts, pts + n, comp );
		ll tot = 0;
		for( int i = 1; i < n; i++ ) tot += pts[i].x[c] - pts[0].x[c];
		pts[0].d += tot;
		for( int i = 1; i < n; i++ )
		{
			tot += ( 2 * i - n ) * ( pts[i].x[c] - pts[i-1].x[c] );
			pts[i].d += tot;
		}
	}

	ll ans = pts[0].d;
	for( int i = 1; i < n; i++ ) ans = min( ans, pts[i].d );
	printf( "%lld\n", ans / 2 );

	return 0;
}
