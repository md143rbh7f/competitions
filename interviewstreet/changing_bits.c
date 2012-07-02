#include "stdio.h"

#define N 100005
#define L 30

int n, q, a[N/L+1], b[N/L+1], c, bit, i, j, k, * arr;
char A[N], B[N], cmd[10];

int main()
{
	scanf( "%d%d%s%s", &n, &q, A, B );
	for( i = 0; i < n; i++ )
	{
		j = i/L, k = i%L;
		a[j] ^= ( A[n-i-1] - '0' ) << k;
		b[j] ^= ( B[n-i-1] - '0' ) << k;
	}

	while(q--)
	{
		scanf( "%s%d", cmd, &i );
		j = i/L, k = i%L;
		if( cmd[4] == 'c' )
		{
			bit = 0;
			for( i = 0; i <= j; i++ ) c = a[i] + b[i] + bit, bit = c >> L;
			printf( "%d", 1 & ( c >> k ) );
		}
		else
		{
			scanf( "%d", &bit );
			arr = cmd[4] == 'a' ? a : b;
			arr[j] ^= ( arr[j] & ( 1 << k ) ) ^ ( bit << k );
		}
	}
	return 0;
}
