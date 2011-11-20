#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

double cross( double x0, double y0, double x1, double y1 )
{
	return x0 * y1 - x1 * y0;
}

bool intersects( double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3 )
{
	double a = cross( x1 - x0, y1 - y0, x2 - x0, y2 - y0 );
	double b = cross( x1 - x0, y1 - y0, x3 - x0, y3 - y0 );
	double c = cross( x3 - x2, y3 - y2, x0 - x2, y0 - y2 );
	double d = cross( x3 - x2, y3 - y2, x1 - x2, y1 - y2 );
	return ( ( a >= 0 && b <= 0 ) || ( a <= 0 && b >= 0 ) ) && ( ( c >= 0 && d <= 0 ) || ( c <= 0 && d >= 0 ) );
}

int main()
{
	int x0, y0, x1, y1, x2, y2, x3, y3;
	double ans;
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d%d%d%d", &x0, &y0, &x1, &y1 );
		if( !x0 && !y0 && !x1 && !y1 ) break;
		scanf( "%d%d%d%d", &x2, &y2, &x3, &y3 );
		if( intersects( x0, y0, x1, y1, x2, y2, x3, y3 ) )
		{
			double a = hypot( x0 - x2, y0 - y2 ) + hypot( x1 - x2, y1 - y2 );
			double b = hypot( x0 - x3, y0 - y3 ) + hypot( x1 - x3, y1 - y3 );
			ans = 0.5 * min( a, b );
		}
		else ans = 0.5 * hypot( x0 - x1, y0 - y1 );
		printf( "Case %d: %.3lf\n", case_num, ans );
	}
	return 0;
}
