#include <stdio.h>

int ans, i, j, k, l, m, ok[11];

int main()
{
	for( i = 1; i < 10000; i++ )
	{
		ok[10] = 1, l = 0, m = 0;
		for( j = 1; l < 9; j++ )
		{
			k = i*j;
			while(k)
			{
				if( l==9 )
				{
					ok[10] = 0;
					break;
				}
				k /= 10;
				m *= 10;
				l++;
			}
			m += i*j;
		}
		for( j = 1; j < 10; j++ ) ok[j] = 0;
		for( k = m; k; k /= 10 ) ok[k%10] = 1;
		for( j = 1; j < 10; j++ ) ok[10] &= ok[j];
		if( ok[10] && m > ans ) ans = m;
	}
	printf( "%d\n", ans );
	return 0;
}
