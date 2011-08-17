#define MAX 2501

// [total symbols][paired symbols]
double f[MAX][MAX];

struct PerfectMemory
{
	double getExpectation( int x, int y )
	{
		int n = x * y;
		for( int i = 1; i <= n; i++ )
		{
			f[i][0] = i;
			for( int j = 2; j <= i; j += 2 )
				f[i][j]
				= 1.0 * (i-j) / i * ( 1 + f[i-1][j] )
				+ 1.0 * j / i / (i-1) * ( 1 + f[i-2][j-2] )
				+ 1.0 * j * (i-j) / i / (i-1) * ( 2 + f[i-2][j-2] )
				+ 1.0 * j * (j-2) / i / (i-1) * ( 1 + ( j >= 4 ? f[i-2][j-4] : 0 ) )
				;
		}
		return f[n][n];
	}
};
