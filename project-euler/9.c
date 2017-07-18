#include <math.h>
#include <stdio.h>

#define MAX 1000

int a, b, c;

int main()
{
	for( a = 1; a < MAX; a++ ) for( b = a; b < MAX; b++ )
	{
		c = (int)(sqrt(a*a+b*b));
		if( a*a + b*b == c*c && a + b + c == MAX ) printf( "%d\n", a*b*c );
	}
	return 0;
}
