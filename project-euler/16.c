#include <stdio.h>

#define N 1000

int n[N], i, j, ans;

int main()
{
	n[0] = 1;
	for( i = 0; i < N; i++ )
	{
		for( j = 0; j+1 < N; j++ ) n[j] *= 2;
		for( j = 0; j+1 < N; j++ ) n[j+1] += n[j]/10, n[j] %= 10;
	}
	for( i = 0; i < N; i++ ) ans += n[i];
	printf( "%d\n", ans );
	return 0;
}
