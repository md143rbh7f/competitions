#include "stdio.h"

int a, b, i;
char buf[11];

int main()
{
	scanf( "%d%s", &a, buf );
	while( buf[i+1] ) i++;
	while( i >= 0 ) b = 10 * b + buf[i] - '0', i--;
	printf( "%d\n", a + b );
	return 0;
}
