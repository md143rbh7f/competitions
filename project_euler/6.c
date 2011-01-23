#include <stdio.h>

int i, n, m;

int main()
{
	for( i = 1; i <= 100; i++ ) m += i;
	n += m*m;
	for( i = 1; i <= 100; i++ ) n -= i*i;
	printf( "%d\n", n );
	return 0;
}
