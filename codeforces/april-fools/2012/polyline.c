#include "stdio.h"

int x, y, u, v, d = 1, a, b;

int main()
{
	scanf( "%d%d", &a, &b );
	while( a )
	{
		switch( b % 4 )
		{
			case 0: u = y, v = x; break;
			case 1: u = x, v = y + d; break;
			case 2: u = x + d, v = y + d; break;
			case 3: u = 2 * d - y - 1, v = d - x - 1; break;
		}
		x = u, y = v;
		d *= 2;
		a--;
		b /= 4;
	}
	printf( "%d %d\n", x, y );
	return 0;
}
