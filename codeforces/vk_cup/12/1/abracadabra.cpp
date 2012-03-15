#include <algorithm>
#include <cstdio>

using namespace std;

int rec( int a, int b, int c, int d, int m )
{
	if( a>c || ( a==c && b>d ) ) return rec( c, d, a, b, m );
	if( b>=d ) return 1+d-c;
	if( a==c ) return 1+b-a;
	if( a>m ) return rec( a-m, b-m, c-m, d-m, m/2 );
	if( c>m ) return rec( a, b, c-m, d-m, m );
	if( d<m ) return rec( a, b, c, d, m/2 );
	if( b<m ) return max( rec( a, b, c, m-1, m/2 ), rec( a, b, 1, d-m, m/2 ) );
	return max( 1+b-c, rec( a, m-1, 1, d-m, m/2 ) );
}

int main()
{
	int a, b, c, d;
	scanf( "%d%d%d%d", &a, &b, &c, &d );
	printf( "%d\n", rec( a, b, c, d, 1<<29 ) );
	return 0;
}
