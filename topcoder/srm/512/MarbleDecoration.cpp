#include <algorithm>

using namespace std;

int c[3];

struct MarbleDecoration
{
	int maxLength( int r, int g, int b )
	{
		c[0] = r, c[1] = g, c[2] = b;
		sort( c, c + 3 );
		return min( 2 * c[1] + 1, 2 * c[2] );
	}
};
