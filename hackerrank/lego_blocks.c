#include "stdio.h"

#define N 1005
#define F 4
#define MOD 1000000007

int rows[N], tot[N][N], good_mem[N][N], seen[N][N];

int good( int n, int m )
{
	int *ans = &good_mem[n][m], i;
	if( seen[n][m] ) return *ans;
	*ans = tot[n][m];
	for( i = 1; i < m; i++ ) *ans = ( *ans + MOD - ( ( (long long) good( n, i ) * tot[n][m-i] ) % MOD ) ) % MOD;
	seen[n][m] = 1;
	return *ans;
}

int main()
{
	int t, n, m;

	rows[0] = 1;
	for( m = 1; m < N; m++ ) for( t = 1; t <= F; t++ ) if( m >= t ) rows[m] = ( rows[m] + rows[m-t] ) % MOD;

	for( m = 0; m < N; m++ ) tot[0][m] = 1;
	for( n = 1; n < N; n++ ) for( m = 0; m < N; m++ ) tot[n][m] = ( (long long) tot[n-1][m] * rows[m] ) % MOD;

	scanf( "%d", &t );
	while( t-- )
	{
		scanf( "%d%d", &n, &m );
		printf( "%d\n", good( n, m ) );
	}
	return 0;
}
