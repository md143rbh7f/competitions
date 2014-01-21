#include "stdio.h"

#define N 1000007

int n, p[N];
long long ans = 1, cnt, i, j;

int main()
{
	scanf( "%d", &n );
	for( i = 2; i <= n; i++ ) p[i] = 1;
	for( i = 2; i <= n; i++ ) if( p[i] )
	{
		for( j = 2 * i; j <= n; j += i ) p[j] = 0;
		cnt = 0;
		for( j = i; j <= n; j *= i ) cnt += n / j;
		ans = ( ans * ( 2 * cnt + 1 ) ) % N;
	}
	printf( "%d\n", (int) ans );
	return 0;
}
