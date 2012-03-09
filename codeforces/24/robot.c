#include "stdio.h"

#define MAX 1000

int n, m, x, y, I, i, j;
double p[2][MAX], a[MAX];

int main()
{
	scanf( "%d%d%d%d", &n, &m, &x, &y );
	x--, y--;
	for( I = n-2; I >= x; I-- )
	{
		i = I%2;
		for( j = 0; j < m; j++ ) a[j] = (j>0) + (j<m-1) + 1, p[i][j] = 2 + p[1-i][j] + (j>0) + (j<m-1);
		for( j = 0; j < m-1; j++ ) a[j+1] += -1/a[j], p[i][j+1] += p[i][j]/a[j];
		for( j = m-1; j > 0; j-- ) p[i][j-1] += p[i][j]/a[j];
		for( j = 0; j < m; j++ ) p[i][j] /= a[j];
	}
	printf( "%0.10lf", p[x%2][y] );
	return 0;
}
