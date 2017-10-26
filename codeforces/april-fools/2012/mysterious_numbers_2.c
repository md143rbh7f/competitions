#include "stdio.h"

int a, b, c, n;

int main()
{
	scanf( "%d%d%d", &a, &b, &n );
	while( n-- ) c = a + b, a = b, b = c;
	printf( "%d\n", a );
	return 0;
}
