#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAX 210

double cost[MAX][MAX], dp[MAX][MAX];
int T, N, C, x[MAX];

int main()
{
	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d%d", &N, &C );
		for( int i = 0; i < N; i++ ) scanf( "%d", &x[i] );
		for( int i = 0; i < N; i++ ) for( int j = i + 1; j < N; j++ )
		{
			cost[i][j] = 0;
			for( int k = i + 1; k < j; k++ ) cost[i][j] += abs( x[i] + 1.0 * ( x[j] - x[i] ) * ( k - i ) / ( j - i ) - x[k] );
		}
		for( int i = 1; i < N; i++ )
		{
			dp[i][2] = cost[0][i];
			for( int c = 3; c <= C; c++ )
			{
				dp[i][c] = dp[i][c-1];
				for( int j = 1; j <= i; j++ ) dp[i][c] = min( dp[i][c], dp[j][c-1] + cost[j][i] );
			}
		}
		printf( "%.4lf\n", dp[N-1][C]/N );
	}
	return 0;
}
