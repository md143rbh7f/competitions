#include "stdio.h"

#define MAX 1005

int i, j, a, b, u, v, markers[MAX][MAX], caps[MAX][MAX];

int main()
{
	scanf( "%d%d", &i, &j );
	while(i--)
	{
		scanf( "%d%d", &a, &b );
		markers[a][b]++;
	}
	while(j--)
	{
		scanf( "%d%d", &a, &b );
		if( markers[a][b] )
		{
			markers[a][b]--;
			u++, v++;
		}
		else caps[a][b]++;
	}
	for( j = 0; j < MAX; j++ )
	{
		a = b = 0;
		for( i = 0; i < MAX; i++ ) a += markers[i][j], b += caps[i][j];
		u += a < b ? a : b;
	}
	printf( "%d %d\n", u, v );
	return 0;
}
