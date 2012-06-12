#include "stdio.h"
#include "string.h"

int i, j;
char buf[100005];

int main()
{
	scanf( "%s", buf );
	for( i = strlen(buf) - 2, j = i + 1; i >= 0; i-- ) if( buf[i] >= buf[j] ) buf[--j] = buf[i];
	printf( "%s\n", buf + j );
	return 0;
}
