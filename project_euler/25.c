#include <stdio.h>

#define L 1000

int f[2][L], N, n, i;

int main()
{
	for( f[1][0] = 1; !f[n][L-1]; N++, n = 1-n ) for( i = 0; i+1 < L; i++ ) f[n][i] += f[1-n][i], f[n][i+1] += f[n][i]/10, f[n][i] %= 10;
	printf( "%d\n", N );
	return 0;
}
