#include <cmath>
#include <vector>

using namespace std;

#define f(q) hypot( q, width[n] ) / swim[n] + rec( n + 1, need - ( q ) )

int walk, ITER = 100;
vector<int> width, swim;
double R = ( 3 - sqrt( 5 ) ) / 2;

double rec( int n, double need )
{
	if( n == 3 ) return need / walk;

	double x = 0, y = need, tx, ty;
	bool ex = true, ey = true;
	for( int i = 0; i < ITER; i++ )
	{
		double d = R * ( y - x );
		if( ex ) tx = f( x + d ), ex = false;
		if( ey ) ty = f( y - d ), ey = false;
		if( tx < ty ) y -= d, ty = tx, ex = true;
		else x += d, tx = ty, ey = true;
	}

	return tx;
}

struct EllysThreeRivers
{
	double getMin( int height, int _walk, vector<int> _width, vector<int> _swim )
	{
		walk = _walk, width = _width, swim = _swim;
		return rec( 0, height );
	}
};
