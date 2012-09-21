#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

bool run()
{
	double l;
	scanf( "%lf", &l );
	if( l < 0 ) return false;

	vector< pair< double, double > > x;
	for(;;)
	{
		double a, b;
		scanf( "%lf%lf", &a, &b );
		if( a > b ) break;
		a = max( a, 0.0 ), b = min( b, l );
		x.push_back( make_pair( a, b ) );
	}
	sort( x.begin(), x.end() );

	double a = 0, b = 0;
	for( int i = 0; i < x.size(); i++ )
	{
		if( x[i].first > b )
		{
			l -= b - a;
			a = x[i].first;
			b = x[i].second;
		}
		else if( x[i].second > b ) b = x[i].second;
	}
	l -= b - a;
	printf( "The total planting length is %.1lf\n", l );
	return true;
}

int main()
{
	while(run());
	return 0;
}
