#include <stdio.h>

#define MAX 20

int i, j;
long long dp[MAX+1][MAX+1];

int main()
{
	dp[0][0] = 1;
	for( i = 0; i <= MAX; i++ ) for( j = 0; j <= MAX; j++ )
	{
		if(i) dp[i][j] += dp[i-1][j];
		if(j) dp[i][j] += dp[i][j-1];
	}
	printf( "%lld\n", dp[MAX][MAX] );
	return 0;
}
