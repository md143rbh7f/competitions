#include "math.h"
#include "stdio.h"

#define MAX 110
#define BIG 111111

int C, N, i, j, k;
double x[MAX], y[MAX];

int main()
{
	for( C = 1; ; C++ )
	{
		scanf( "%d", &N );
		if( !N ) break;
		for( i = 0; i < N; i++ ) scanf( "%lf%lf", &x[i], &y[i] );
		double ans = BIG;
		for( i = 0; i < N; i++ ) for( j = i+1; j < N; j++ )
		{
			double dx0 = x[j] - x[i], dy0 = y[j] - y[i];
			double len = hypot( dx0, dy0 );
			dx0 /= len, dy0 /= len;
			double max = 0, min = 0;
			for( k = 0; k < N; k++ )
			{
				double dx1 = x[k] - x[i], dy1 = y[k] - y[i];
				double cross = dx0 * dy1 - dx1 * dy0;
				if( cross > max ) max = cross;
				if( cross < min ) min = cross;
			}
			if( max - min < ans ) ans = max - min;
		}
		printf( "Case %d: %.2lf\n", C, ans );
	}
	return 0;
}
