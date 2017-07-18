#include <stdio.h>

#define N 100
#define MAX 1000000

int c[N+1][N+1], i, j, ans;

int main()
{
	for( i = 0; i <= N; i++ ) for( j = 0; j <= i; j++ )
	{
		c[i][j] = j ? c[i-1][j-1] + c[i-1][j] : 1;
		if( c[i][j] > MAX ) c[i][j] = MAX+1, ans++;
	}
	printf( "%d\n", ans );
	return 0;
}
