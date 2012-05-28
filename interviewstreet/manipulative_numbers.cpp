#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[105], b;

int main()
{
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) scanf( "%d", &a[i] );
	for( b = -1; ; b++ )
	{
		sort( a, a+n );
		int cnt = 0;
		for( int i = 0, j = 0; i < n; i = j )
		{
			for( ; j < n && a[i] == a[j]; j++ );
			cnt = max( cnt, j - i );
		}
		if( 2 * cnt > n ) break;
		for( int i = 0; i < n; i++ ) a[i] /= 2;
	}
	printf( "%d\n", b );
	return 0;
}
