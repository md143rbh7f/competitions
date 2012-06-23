#include "stdio.h"

int main()
{
	int k, b, n, t;
	scanf( "%d%d%d%d", &k, &b, &n, &t );
	long long m = 1;
	while( n >= 1 && k * m + b <= t ) m = k * m + b, n--;
	printf( "%d\n", n );
	return 0;
}
