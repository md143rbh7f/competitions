#include <stdio.h>
#include <math.h>

typedef long long ll;

int T, t, l, p, c, ans;
ll a, b;

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d%d%d", &l, &p, &c );
		ans = 0, a = l, b = p;
		while( b > c*a )
		{
			b = (ll)ceil(sqrt(a*b));
			ans++;
		}
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
