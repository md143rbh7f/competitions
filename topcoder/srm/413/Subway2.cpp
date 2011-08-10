#include <cmath>

using namespace std;

struct Subway2
{
	double minTime( int d, int a, int v )
	{
		if( d > 1.0 * v * v / a ) return 1.0 * v / a + 1.0 * d / v;
		return 2.0 * sqrt( 1.0 * d / a );
	}
};
