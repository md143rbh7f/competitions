#include <stdio.h>

#define MAX 10000

int p[MAX], i, j, ok;

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i < MAX; i++ )
	{
		if(p[i]) for( j = 2*i; j < MAX; j += i ) p[j] = 0;
		else if(i%2) for( ok = j = 1; 2*j*j < i; j++ ) if(p[i-2*j*j]) ok = 0;
		if(ok)
		{
			printf( "%d\n", i );
			break;
		}
	}
	return 0;
}
