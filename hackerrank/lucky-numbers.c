#include "stdio.h"

#define L 18
#define D 9
#define MAX1 (L*D)
#define MAX2 (L*D*D)

int prime[MAX2+1];
long long power[L+1], cnt[L+1][MAX1+1][MAX2+1];

long long ways( long long n, int i, int j, int k )
{
	if( i < 0 ) return 0;
	int d = n / power[i];
	long long ans = ways( n - d * power[i], i - 1, j + d, k + d * d );
	while( --d >= 0 ) ans += cnt[i][j+d][k+d*d];
	return ans;
}

int main()
{
	long long a, b;
	int i, j, k, d, t;

	power[0] = 1;
	for( i = 1; i <= L; i++ ) power[i] = power[i-1] * ( D + 1 );

	for( i = 2; i <= MAX2; i++ ) prime[i] = 1;
	for( i = 2; i <= MAX2; i++ ) if( prime[i] ) for( j = 2 * i; j <= MAX2; j += i ) prime[j] = 0;

	for( j = 0; j <= MAX1; j++ ) for( k = 0; k <= MAX2; k++ ) cnt[0][j][k] = prime[j] && prime[k];

	for( i = 1; i <= L; i++ )
	for( j = 0; j <= MAX1; j++ )
	for( k = 0; k <= MAX2; k++ )
	for( d = 0; d <= D; d++ )
	if( j + d <= MAX1 && k + d * d <= MAX2 )
		cnt[i][j][k] += cnt[i-1][j+d][k+d*d];

	scanf( "%d", &t );
	while(t--)
	{
		scanf( "%lld%lld", &a, &b );
		printf( "%lld\n", ways( b + 1, L, 0, 0 ) - ways( a, L, 0, 0 ) );
	}
}
