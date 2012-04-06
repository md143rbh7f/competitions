#include "stdio.h"

int n;

int main()
{
	scanf( "%d", &n );
	printf( "%d\n", 6 * n * ( n - 1 ) + 1 );
	return 0;
}
