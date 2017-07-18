#include <stdio.h>

#define MAX1 10000
#define MAX2 30000

int d[MAX2], i, j, ans;

int main()
{
	for( i = 0; i < MAX2; i++ ) for( j = 1; j < i; j++ ) if( i%j==0 ) d[i] += j;
	for( i = 0; i < MAX1; i++ ) if( d[i]!=i && d[d[i]]==i ) ans += i;
	printf( "%d\n", ans );
	return 0;
}
