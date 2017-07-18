#include <stdio.h>

#define L 200

int d[L], ans, i, j;

int main()
{
	d[0] = 1;
	for( i = 1; i <= 100; i++ )
	{
		for( j = 0; j+2 < L; j++ ) d[j] *= i;
		for( j = 0; j+2 < L; j++ )
		{
			d[j+2] += d[j]/100;
			d[j] %= 100;
			d[j+1] += d[j]/10;
			d[j] %= 10;
		}
	}
	for( j = 0; j < L; j++ ) ans += d[j];
	printf( "%d\n", ans );
	return 0;
}
