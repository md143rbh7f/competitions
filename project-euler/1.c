#include <stdio.h>

int i, ans;

int main()
{
	for( i = 1; i < 1000; i++ ) if( (i%3)==0 || (i%5)==0 ) ans += i;
	printf( "%d\n", ans );
	return 0;
}
