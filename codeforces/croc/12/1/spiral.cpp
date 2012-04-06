#include <cstdio>

using namespace std;

#define N 505

int n, m, ans, grid[N][N], sum[N][N], spiral[N][N];

int main()
{
	scanf( "%d%d", &n, &m );

	for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
	{
		scanf( "%d", &grid[i][j] );
		spiral[i][j] = grid[i][j];
		sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + grid[i][j];
	}

	int ans = -1234567890;
	for( int s = 3; s <= n && s <= m; s += 2 ) for( int i = 0; i + s <= n; i++ ) for( int j = 0; j + s <= m; j++ )
	{
		spiral[i][j] = sum[i+s][j+s] - sum[i][j+s] - sum[i+s][j] + sum[i][j] - spiral[i+1][j+1] - grid[i+1][j];
		if( spiral[i][j] > ans ) ans = spiral[i][j];
	}
	
	printf( "%d\n", ans );

	return 0;
}
