#include <stdio.h>

int i, j, k, c[10], d[10], ok;

int main()
{
	for( i = 1; !ok; i++ )
	{
		for( j = 0; j < 10; j++ ) c[j] = 0;
		for( j = i; j; j/=10 ) c[j%10]++;
		ok = 1;
		for( k = 2; k < 6; k++ )
		{
			for( j = 0; j < 10; j++ ) d[j] = 0;
			for( j = k*i; j; j/=10 ) d[j%10]++;
			for( j = 0; j < 10; j++ ) if(d[j]!=c[j]) ok = 0;
		}
		if(ok) printf( "%d\n", i );
	}
	return 0;
}
