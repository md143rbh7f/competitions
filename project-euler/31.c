#include <stdio.h>

#define N 8
#define MAX 200

int v[] = { 1, 2, 5, 10, 20, 50, 100, 200 }, dp[MAX+1], i, j;

int main()
{
	dp[0] = 1;
	for( i = 0; i < N; i++ ) for( j = 0; j + v[i] <= MAX; j++ ) dp[j+v[i]] += dp[j];
	printf( "%d\n", dp[MAX] );
	return 0;
}
