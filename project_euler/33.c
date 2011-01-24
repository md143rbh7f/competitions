#include <stdio.h>

int a, b, a0, a1, b0, b1, c, d, e = 1, f = 1;

int main()
{
	for( a0 = 1; a0 < 10; a0++ ) for( a1 = 1; a1 < 10; a1++ ) for( b0 = 1; b0 < 10; b0++ ) for( b1 = 1; b1 < 10; b1++ )
	{
		a = a1*10+a0, b = b1*10+b0;
		if( a<b && ( (a0==b0) + (a0==b1) + (a1==b0) + (a1==b1) ) == 1 )
		{
			c = a, d = b;
			if(a0==b0) c /= 10, d /= 10;
			if(a0==b1) c /= 10, d %= 10;
			if(a1==b0) c %= 10, d /= 10;
			if(a1==b1) c %= 10, d %= 10;
			if( a*d == b*c ) e *= c, f *= d;
		}
	}
	while( f%e==0 ) f /= e;
	printf( "%d\n", f );
	return 0;
}
