#include <stdio.h>

int a = 1, b = 1, c = 2, ans;

int main()
{
	while( c <= 4000000 )
	{
		if( (c%2)==0 ) ans += c;
		a = b;
		b = c;
		c = a+b;
	}
	printf( "%d", ans );
	return 0;
}
