#include <algorithm>
#include <cstdio>

using namespace std;

#define L 1000

int n, v[105];

int main()
{
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) scanf( "%d", &v[i] );
	sort( v, v + n );

	int ans = 400000 * ( n / 2 ) * ( n / 2 + ( n % 2 ) ), b = 0;
	while( ( v[(b+n-1)%n] + 1 ) % L == v[b] ) b++;
	for( int i = 0, j = 0; i < n; i = j )
	{
		for( j = i + 1; j < n && ( v[(b+j+n-1)%n] + 1 ) % L == v[(b+j)%n]; j++ );
		ans += ( j - i ) / 2 * 2;
	}

	printf( "%d\n", ans );

	return 0;
}
