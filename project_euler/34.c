#include <stdio.h>

int f[10], i, j, k, ans;

int main()
{
	f[0] = 1;
	for( i = 1; i < 10; i++ ) f[i] = i*f[i-1];
	for( i = 0; i < 1000000; ans += i==k ? i : 0, i++ ) for( j = i, k = 0; j; k += f[j%10], j /= 10 );
	printf( "%d\n", ans-3 );
	return 0;
}
