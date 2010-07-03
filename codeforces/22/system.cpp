#include <cstdio>

using namespace std;

int n, m, v, bad;

int main()
{
	scanf( "%d%d%d", &n, &m, &v );
	if( m<n-1 || m>((long long)(n-1))*(n-2)/2+1 )
	{
		printf( "-1" );
		return 0;
	}
	int bad = (v%n)+1;
	printf( "%d %d\n", v, bad );
	for( int i = 1; i <= n; i++ ) if( i!=bad )
	for( int j = i+1; j <= n; j++ ) if( j!=bad )
	{
		if( !(--m) ) return 0;
		printf( "%d %d\n", i, j );
	}
	return 0;
}
