#include <algorithm>
#include <cstdio>

using namespace std;

int T, n, a[20010], ans;

int main()
{
	scanf( "%d", &T );
	while(T--)
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ ) scanf( "%d", &a[i] );
		sort( a, a+n );
		ans = 0;
		for( int i = 2; i < n; i += 3 ) ans += a[n-i-1];
		printf( "%d\n", ans );
	}
	return 0;
}
