#include <cmath>

using namespace std;

struct MagicalGirlLevelOneDivTwo
{
	double theMinDistance( int d, int x, int y )
	{
		if( x < 0 ) x = -x;
		if( y < 0 ) y = -y;
		if( x < y )
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		if( x <= d ) return 0;
		if( y <= d ) return x - d;
		return hypot( x - d, y - d );
	}
};
