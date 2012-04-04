#include "stdio.h"

char base[25], buf[25];
int n, ans, i;

int main()
{
	scanf( "%d%s", &n, base );
	while( base[ans] ) ans++;
	while( --n )
	{
		scanf( "%s", buf );
		for( i = 0; i <= ans && base[i] == buf[i]; i++ );
		if( i < ans ) ans = i;
	}
	printf( "%d\n", ans );
	return 0;
}
