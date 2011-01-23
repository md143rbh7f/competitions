#include <stdio.h>

#define MAX 10001

int p[MAX], i = 2, j, n, ok;

int main()
{
	while( n < MAX )
	{
		ok = 1;
		for( j = 0; j < n; j++ ) if( (i%p[j])==0 )
		{
			ok = 0;
			break;
		}
		if(ok) p[n++] = i;
		i++;
	}
	printf( "%d\n", p[MAX-1] );
	return 0;
}
