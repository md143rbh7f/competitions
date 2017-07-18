#include <stdio.h>

int i, j, k, l, s, ans;

int main()
{
	for( i = 0; i < 1000000; i++ )
	{
		s = 0;
		for( j = i; j; j/=10 )
		{
			k = 1;
			for( l = 0; l < 5; l++ ) k *= j%10;
			s += k;
		}
		if( s==i ) ans += s;
	}
	printf( "%d\n", ans-1 );
	return 0;
}
