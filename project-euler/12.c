#include <stdio.h>

int i = 1, j, k, n, d;

int main()
{
	while(1)
	{
		n = i*(i+1)/2, d = 1, j = 2;
		while( j <= n )
		{
			k = 1;
			while( (n%j)==0 ) k++, n /= j;
			d *= k, j++;
		}
		if( d > 500 )
		{
			printf( "%d\n", i*(i+1)/2 );
			break;
		}
		i++;
	}
	return 0;
}
