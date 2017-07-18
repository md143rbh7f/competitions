#include <stdio.h>

#define L 1024

int n[2][L], I, i, j, ans;

void add( int * a, int * b )
{
	for( j = 0; j+1 < L; j++ )
	{
		b[j] += a[j];
		b[j+1] += b[j]/10;
		b[j] %= 10;
	}
}

int main()
{
	n[0][0] = n[1][0] = 1;
	for( I = 0; I < 1000; I++ )
	{
		// i is denominator, 1-i is numerator
		i = I%2;
		add( n[1-i], n[i] );
		add( n[i], n[1-i] );
		for( j = L-1; !n[i][j]; j-- );
		if( n[1-i][j+1] ) ans++;
	}
	printf( "%d\n", ans );
	return 0;
}
