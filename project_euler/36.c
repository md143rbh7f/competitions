#include <stdio.h>

int i, j, l, ok, ans, b, B[] = { 2, 10 }, tmp[20];

int main()
{
	for( i = 0; i < 1000000; i++ )
	{
		ok = 1;
		for( b = 0; b < 2; b++ )
		{
			for( l = 0, j = i; j; tmp[l++] = j%B[b], j /= B[b] );
			for( j = 0; j < l; j++ ) ok &= tmp[j]==tmp[l-j-1];
		}
		if( ok ) ans += i;
	}
	printf( "%d\n", ans );
	return 0;
}
