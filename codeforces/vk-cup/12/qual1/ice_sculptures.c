#include "stdio.h"

#define INF 12345678
#define MAX 20005

int t[MAX], n, i, j, k, sum, ans;

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) scanf( "%d", &t[i] );
	ans = -INF;
	for( i = 3; i <= n; i++ ) if( n % i == 0 )
	{
		for( j = 0; j < n/i; j++ )
		{
			sum = 0;
			for( k = j; k < n; k += n/i ) sum += t[k];
			if( sum > ans ) ans = sum;
		}
	}
	printf( "%d\n", ans );
	return 0;
}
