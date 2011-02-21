#include <stdio.h>

#define L 200

int a, b, i, j, x, y, m[L+1], n[2][L+1], ans;

int main()
{
	for( a = 1; a < 100; a++ )
	{
		for( i = 0; i < L; i++ ) m[i] = n[0][i] = n[1][i] = 0;
		for( i = a, j = 0; i; i /= 10, j++ ) m[j] = n[1][j] = i%10;
		for( b = 1; b < 100; b++ )
		{
			i = b%2, j = 1-i, y = 0;
			for( x = 0; x < L; x++ ) y += n[i][x];
			if( y > ans ) ans = y;
			for( x = 0; x < L; x++ ) for( y = 0; x+y < L; y++ ) n[j][x+y] += m[x]*n[i][y];
			for( x = 0; x < L; x++ ) n[j][x+1] += n[j][x]/10, n[j][x] %= 10, n[i][x] = 0;
		}
	}
	printf( "%d\n", ans );
	return 0;
}
